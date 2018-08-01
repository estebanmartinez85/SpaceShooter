// Fill out your copyright notice in the Description page of Project Settings.

#include "StartGame.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"


void AStartGame::StartGame() {
	UWorld* TheWorld = GetWorld();

	FString CurrentLevel = TheWorld->GetMapName();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *CurrentLevel);
	if (CurrentLevel == "UEDPIE_0_MainMenu")
	{
		UGameplayStatics::OpenLevel(GetWorld(), "LevelOne");
	}
	else
	{
		UGameplayStatics::OpenLevel(GetWorld(), "MainMenu");
	}
}

