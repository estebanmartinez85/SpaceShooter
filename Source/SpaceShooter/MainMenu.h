// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API AMainMenu : public ALevelScriptActor
{

	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = LevelBlueprint)
	void StartGame();
	
	
};
