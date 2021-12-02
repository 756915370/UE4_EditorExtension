// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "MenuItem/MenuItem.h"
#include "UObject/Object.h"
#include "MenuManager.generated.h"

struct FMenuItemNode
{
	FString NodeName;
	UMenuItem* MenuItem = nullptr;
	TArray<FMenuItemNode> Children;
};

/**
* 
*/
UCLASS()
class EDITOREXTENSIONEDITOR_API UMenuManager : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

private:
	TArray<FMenuItemNode> RootNodeList;

private:
	void AddMenuBarExtension(class FMenuBarBuilder& Builder);
	void AddMenuItemToNodeList(UMenuItem* MenuItem);
};
