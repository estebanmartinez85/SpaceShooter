// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerHello.h"
#include "GameFramework/Actor.h"

ATriggerHello::ATriggerHello()
{
	OnActorBeginOverlap.AddDynamic(this, &ATriggerHello::OnOverlapBegin);
}

void ATriggerHello::BeginPlay()
{
	Super::BeginPlay();
}

void ATriggerHello::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("%s HIT %s"), *OverlappedActor->GetName(), *OtherActor->GetName());
}
