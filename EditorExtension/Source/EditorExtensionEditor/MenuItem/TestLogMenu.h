// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "MenuItem.h"
#include "UObject/Object.h"
#include "TestLogMenu.generated.h"

/**
 * 
 */
UCLASS()
class EDITOREXTENSIONEDITOR_API UTestLogMenu : public UMenuItem
{
	GENERATED_BODY()
	UTestLogMenu();
public:
	virtual void OnMenuClick() override;
};
