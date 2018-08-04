// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerFollow.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Config.h"


// Sets default values for this component's properties
UPlayerFollow::UPlayerFollow()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerFollow::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlayerFollow::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	//FVector current = GetOwner()->GetActorLocation();
	//GetOwner()->SetActorLocation(FVector(0, 0, Config::VerticalSpeed) + current);
}

