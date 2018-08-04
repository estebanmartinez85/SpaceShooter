// Fill out your copyright notice in the Description page of Project Settings.

#include "ShipController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "EngineUtils.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Components/InputComponent.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Engine/StaticMeshActor.h"
#include "Config.h"
#include "TriggerHello.h"

// Sets default values for this component's properties
UShipController::UShipController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UClass> LaserClassFinder(TEXT("Blueprint'/Game/PlayerShip_Sprite_Blueprint.PlayerShip_Sprite_Blueprint_C'"));
	laser = LaserClassFinder.Object;
	
}


// Called when the game starts
void UShipController::BeginPlay()
{
	Super::BeginPlay();

	// ...
	SetupInputComponent(); 
}


// Called every frame
void UShipController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	//FVector current = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	//GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(FVector(0, 0, Config::VerticalSpeed) + current);
	float speed = 3;
	FVector location = GetOwner()->GetActorLocation();
	
	if ((location.X > -240 && location.X < 240)
		&& (location.Z < 320 && location.Z > -320)) {
		if (MoveUp)
		{
			FVector current = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
			GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(FVector(0, 0, speed) + current);
		}
		if (MoveRight)
		{
			FVector current = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
			GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(FVector(speed, 0, 0) + current);
		}
		if (MoveDown)
		{
			FVector current = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
			GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(FVector(0, 0, -speed) + current);
			if (!laserspawned) {
				FActorSpawnParameters SpawnInfo;
				APaperSpriteActor* newlaser = GetWorld()->SpawnActor<APaperSpriteActor>(laser, GetOwner()->GetActorLocation(), GetOwner()->GetActorRotation(), SpawnInfo);
				//GetWorld()->SpawnActor<APaperSpriteActor>(Location, Rotation, SpawnInfo);
				laserspawned = true;
			}
		}	if (MoveLeft)
		{
			FVector current = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
			GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(FVector(-speed, 0, 0) + current);
		}
	}
	else {
		GetOwner()->SetActorLocation(previousLocation);
	}
	previousLocation = location;
}

/// Look for attached Input Component (only appears at run time)
void UShipController::SetupInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Input component found"))
			//	/// Bind the input axis
			InputComponent->BindAction("Up", IE_Pressed, this, &UShipController::OnUpPressed);
			InputComponent->BindAction("Up", IE_Released, this, &UShipController::OnUpReleased);
			InputComponent->BindAction("Right", IE_Pressed, this, &UShipController::OnRightPressed);
			InputComponent->BindAction("Right", IE_Released, this, &UShipController::OnRightReleased);
			InputComponent->BindAction("Down", IE_Pressed, this, &UShipController::OnDownPressed);
			InputComponent->BindAction("Down", IE_Released, this, &UShipController::OnDownReleased);
			InputComponent->BindAction("Left", IE_Pressed, this, &UShipController::OnLeftPressed);
			InputComponent->BindAction("Left", IE_Released, this, &UShipController::OnLeftReleased);
		//InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing input component"), *GetOwner()->GetName())
	}
}

void UShipController::OnUpPressed() {
	MoveUp = true;
}
void UShipController::OnUpReleased() {
	MoveUp = false;
}
void UShipController::OnRightPressed() {
	MoveRight = true;
}
void UShipController::OnRightReleased() {
	MoveRight = false;
}
void UShipController::OnDownPressed() {
	MoveDown = true;
}
void UShipController::OnDownReleased() {
	MoveDown = false;
}
void UShipController::OnLeftPressed() {
	MoveLeft = true;
}
void UShipController::OnLeftReleased() {
	MoveLeft = false;
}