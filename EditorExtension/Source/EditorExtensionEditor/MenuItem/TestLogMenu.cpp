// Fill out your copyright notice in the Description page of Project Settings.


#include "TestLogMenu.h"

UTestLogMenu::UTestLogMenu()
{
	InitMenu("/First/Second/Test","TestLog");
}

void UTestLogMenu::OnMenuClick()
{
	UE_LOG(LogTemp, Warning, TEXT("UITestProjectEditor: Log UTestLogMenu"));
}
