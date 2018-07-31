// Fill out your copyright notice in the Description page of Project Settings.


#include "StartComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UStartComponent::UStartComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStartComponent::BeginPlay()
{
	Super::BeginPlay();
	SetupInputComponent();
	// ...
	
}


// Called every frame
void UStartComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


/// Look for attached Input Component (only appears at run time)
void UStartComponent::SetupInputComponent()
{
	
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Input component found"))
			/// Bind the input axis
		InputComponent->BindAction("Enter", IE_Pressed, this, &UStartComponent::StartGame);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing input component"), *GetOwner()->GetName())
	}
}

void UStartComponent::StartGame() {
	UE_LOG(LogTemp, Error, TEXT("ENTER"));
}