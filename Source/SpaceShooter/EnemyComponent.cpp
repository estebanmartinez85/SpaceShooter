// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UEnemyComponent::UEnemyComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	GetOwner()->OnActorBeginOverlap.AddDynamic(this, &UEnemyComponent::OnOverlapBegin);
}


// Called every frame
void UEnemyComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (Activated) {
		GetOwner()->SetActorLocation(FVector(0, 0, -2) + GetOwner()->GetActorLocation());
	}
}

void UEnemyComponent::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	UE_LOG(LogTemp, Error, TEXT("asdasd %s HIT %s"), *OverlappedActor->GetName(), *OtherActor->GetName());
	Activated = true;
}