// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem/InGameMenu.h"

#include "Button.h"

bool UInGameMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (CancelButton == nullptr) return false;
	CancelButton->OnClicked.AddDynamic(this, &UInGameMenu::ReturnToGame);

	if (MainMenuButton == nullptr) return false;
	MainMenuButton->OnClicked.AddDynamic(this, &UInGameMenu::QuitToMainMenu);

	return true;
}

void UInGameMenu::ReturnToGame()
{
	Teardown();
}

void UInGameMenu::QuitToMainMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("Quitting to main menu"));
}
