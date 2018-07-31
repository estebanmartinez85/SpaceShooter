// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


void AMainMenu::StartGame() {
	UE_LOG(LogTemp, Error, TEXT("WORKING"))
	UWorld* TheWorld = GetWorld();

	FString CurrentLevel = TheWorld->GetMapName();
	UE_LOG(LogTemp, Error, TEXT("%s"), *CurrentLevel)
	if (CurrentLevel == "UEDPIE_0_MainMenu")
	{
		UGameplayStatics::OpenLevel(GetWorld(), "LevelOne");
	}
	else
	{
		UGameplayStatics::OpenLevel(GetWorld(), "MainMenu");
	}
}

