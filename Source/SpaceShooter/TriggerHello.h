// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Activatable.h"
#include "Engine/TriggerBox.h"
#include "TriggerHello.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API ATriggerHello : public ATriggerBox, public IActivatable
{
	GENERATED_BODY()
	
protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	// constructor sets default values for this actor's properties
	ATriggerHello();

	// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	
	
};
