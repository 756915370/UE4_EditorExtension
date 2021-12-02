// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuManager.h"

#include "LevelEditor.h"

void UMenuManager::Initialize(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogTemp, Warning, TEXT("UITestProjectEditor MenuManager"));
	for (TObjectIterator<UClass> It; It; ++It)
	{
		UClass* CurrentClass = *It;

		UE_LOG(LogTemp, Warning, TEXT("UITestProjectEditor: 遍历 class %s"), *CurrentClass->GetFName().ToString());
		if (CurrentClass->IsChildOf(UMenuItem::StaticClass()) && !(CurrentClass->HasAnyClassFlags(CLASS_Abstract)))
		{
			UE_LOG(LogTemp, Warning, TEXT("UITestProjectEditor: Add class %s"), *CurrentClass->GetFName().ToString());
			AddMenuItemToNodeList(Cast<UMenuItem>(CurrentClass->GetDefaultObject()));
		}
	}
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuBarExtension("Help",
		                                  EExtensionHook::After,
		                                  nullptr,
		                                  FMenuBarExtensionDelegate::CreateUObject(
			                                  this, &UMenuManager::AddMenuBarExtension));
		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
}

void UMenuManager::Deinitialize()
{
	RootNodeList.Empty();
}

static void AddMenuExtension(FMenuBuilder& Builder, TArray<FMenuItemNode>* NodeList)
{
	for (int i = 0; i < NodeList->Num(); ++i)
	{
		FMenuItemNode& Node = (*NodeList)[i];
		if (Node.MenuItem != nullptr)
		{
			Builder.AddMenuEntry(FText::FromString(Node.MenuItem->GetMenuName()),
			                     FText::FromString(Node.MenuItem->GetMenuToolTip()),
			                     FSlateIcon(),
			                     FUIAction(FExecuteAction::CreateUObject(Node.MenuItem, &UMenuItem::OnMenuClick)));
		}
		else if (!Node.NodeName.IsEmpty() && Node.Children.Num() > 0)
		{
			Builder.AddSubMenu(FText::FromString(Node.NodeName),
			                   FText::FromString(TEXT("")),
			                   FNewMenuDelegate::CreateStatic(&AddMenuExtension, &Node.Children));
		}
	}
}

void UMenuManager::AddMenuBarExtension(FMenuBarBuilder& Builder)
{
	for (FMenuItemNode& Node : RootNodeList)
	{
		if (!Node.NodeName.IsEmpty() && Node.Children.Num() > 0)
		{
			Builder.AddPullDownMenu(FText::FromString(Node.NodeName),
			                        FText::FromString(TEXT("")),
			                        FNewMenuDelegate::CreateStatic(&AddMenuExtension, &Node.Children));
		}
	}
}

static FMenuItemNode* FindMenuItemNode(TArray<FMenuItemNode>& MenuNodes, const FString& MenuName)
{
	for (FMenuItemNode& Node : MenuNodes)
	{
		if (Node.NodeName == MenuName)
		{
			return &Node;
		}
	}
	return nullptr;
}

void UMenuManager::AddMenuItemToNodeList(UMenuItem* MenuItem)
{
	if (MenuItem == nullptr)
	{
		return;
	}
	TArray<FString> MenuNames;
	FString Path = MenuItem->GetMenuPath();
	if (Path.IsEmpty())
	{
		return;
	}
	FString Left;
	while (Path.Split("/", &Left, &Path))
	{
		if (Left.IsEmpty())
		{
			continue;
		}
		MenuNames.Add(Left);
	}
	MenuNames.Add(Path);
	FMenuItemNode* RootMenuNode = FindMenuItemNode(RootNodeList, MenuNames[0]);
	if (RootMenuNode == nullptr)
	{
		FMenuItemNode MenuItemNode;
		MenuItemNode.NodeName = MenuNames[0];
		int32 Index = RootNodeList.Add(MenuItemNode);
		RootMenuNode = &RootNodeList[Index];
	}
	FMenuItemNode* ParentNode = RootMenuNode;
	for (int i = 1; i < MenuNames.Num(); ++i)
	{
		FString& ChildName = MenuNames[i];
		FMenuItemNode* ChildNode = FindMenuItemNode(ParentNode->Children, ChildName);
		if (ChildNode == nullptr)
		{
			FMenuItemNode MenuItemNode;
			MenuItemNode.NodeName = ChildName;
			int32 Index = ParentNode->Children.Add(MenuItemNode);
			ChildNode = &ParentNode->Children[Index];
		}
		ParentNode = ChildNode;
	}
	ParentNode->MenuItem = MenuItem;
}
