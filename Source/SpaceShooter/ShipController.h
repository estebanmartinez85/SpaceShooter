// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "Components/ActorComponent.h"
#include "ShipController.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACESHOOTER_API UShipController : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShipController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void SetupInputComponent();
	void OnUpPressed();
	void OnUpReleased();
	void OnRightPressed();
	void OnRightReleased();
	void OnDownPressed();
	void OnDownReleased();
	void OnLeftPressed();
	void OnLeftReleased();

	UInputComponent* InputComponent = nullptr;
	
private:
	bool MoveUp = false;
	bool MoveRight = false;
	bool MoveDown = false;
	bool MoveLeft = false;

};
