// Fill out your copyright notice in the Description page of Project Settings.

#include "TilingBG.h"
#include "Components/PrimitiveComponent.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Core/Public/Math/Vector.h"

// Sets default values for this component's properties
UTilingBG::UTilingBG()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTilingBG::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTilingBG::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	FVector vector = GetOwner()->GetActorLocation();
	FVector newv = FVector(0, 0, +1);
	GetOwner()->SetActorLocation(newv + vector);
}

