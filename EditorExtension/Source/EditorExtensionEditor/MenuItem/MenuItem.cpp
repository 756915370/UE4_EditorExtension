// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuItem.h"

UMenuItem::UMenuItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}
void UMenuItem::InitMenu(const FString& Path, const FString& Tooltip)
{
	MenuPath = Path;
	MenuToolTip = Tooltip;
	MenuName = FPaths::GetPathLeaf(Path);
}
