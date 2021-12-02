// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MenuItem.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class EDITOREXTENSIONEDITOR_API UMenuItem : public UObject
{
	GENERATED_UCLASS_BODY()
public:
	virtual ~UMenuItem() override
	{
	}
	virtual void OnMenuClick()
	{
	}
private:
	FString MenuPath;
	FString MenuName;
	FString MenuToolTip;
public:
	FString& GetMenuPath() { return MenuPath; }
	FString& GetMenuName() { return MenuName; }
	FString& GetMenuToolTip() { return MenuToolTip; }
protected:
	void InitMenu(const FString& Path, const FString& Tooltip);
};
