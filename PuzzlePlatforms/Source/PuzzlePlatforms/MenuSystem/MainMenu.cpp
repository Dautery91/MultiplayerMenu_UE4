// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem/MainMenu.h"

#include "Button.h"
#include "Kismet/GameplayStatics.h"

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if ((Host == nullptr)) return false;
	Host->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

	if ((Join == nullptr)) return false;
	Join->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);
	
	return true;
}

void UMainMenu::SetMenuInterface(IMenuInterface* MenuInterface)
{
	this->MenuInterface = MenuInterface;
}

void UMainMenu::HostServer()
{
	UE_LOG(LogTemp, Warning, TEXT("Host Button Clicked!"));
	if (MenuInterface != nullptr)
		MenuInterface->Host();
}

void UMainMenu::JoinServer()
{
	UE_LOG(LogTemp, Warning, TEXT("Join Button Clicked!"));
	// if (MenuInterface != nullptr)
	// 	MenuInterface->Join(const FString& Address);
}
