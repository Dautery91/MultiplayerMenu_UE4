// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem/MenuWidget.h"

void UMenuWidget::Setup()
{
	this->AddToViewport();
	this->bIsFocusable = true;

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if ((PlayerController == nullptr)) return;

	FInputModeUIOnly MenuInputMode;
	MenuInputMode.SetWidgetToFocus(this->TakeWidget());
	MenuInputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    
	PlayerController->SetInputMode(MenuInputMode);
	PlayerController->bShowMouseCursor = true;
}

void UMenuWidget::Teardown()
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if ((PlayerController == nullptr)) return;
	const FInputModeGameOnly GameInputMode;
	
	PlayerController->SetInputMode(GameInputMode);
	PlayerController->bShowMouseCursor = false;
	
	this->RemoveFromViewport();
}

void UMenuWidget::SetMenuInterface(IMenuInterface* MenuInterface)
{
	this->MenuInterface = MenuInterface;
}
