// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "StartGame.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API AStartGame : public ALevelScriptActor
{
	GENERATED_BODY()
	
public:
	void StartGame();
	
	
};
