// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem/MainMenu.h"

#include "Button.h"
#include "WidgetSwitcher.h"
#include "Kismet/GameplayStatics.h"

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if ((HostButton == nullptr)) return false;
	HostButton->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

	if ((JoinButton == nullptr)) return false;
	JoinButton->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);

	if ((JoinAcceptButton == nullptr)) return false;
	JoinAcceptButton->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);

	if ((BackButton == nullptr)) return false;
	BackButton->OnClicked.AddDynamic(this, &UMainMenu::OpenMainMenu);

	if ((QuitButton == nullptr)) return false;
	QuitButton->OnClicked.AddDynamic(this, &UMainMenu::QuitGame);
	
	return true;
}

void UMainMenu::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld)
{
	Teardown();
}

void UMainMenu::HostServer()
{
	if (MenuInterface != nullptr)
		MenuInterface->Host();
}

void UMainMenu::OpenJoinMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(JoinMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(JoinMenu);
}

void UMainMenu::OpenMainMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(MainMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(MainMenu);
}

void UMainMenu::JoinServer()
{
	if (MenuInterface != nullptr && IPAddressField != nullptr)
	{
		const FString Address = IPAddressField->GetText().ToString();
		MenuInterface->Join(Address);
		
	}
}

void UMainMenu::QuitGame()
{
	if (MenuInterface == nullptr) return;
	MenuInterface->QuitGame();
}
