// Copyright Epic Games, Inc. All Rights Reserved.


#include "CarSamplePlayerController.h"
#include "CarSamplePawn.h"
#include "CarSampleUI.h"
#include "EnhancedInputSubsystems.h"
#include "ChaosWheeledVehicleMovementComponent.h"

void ACarSamplePlayerController::BeginPlay()
{
	Super::BeginPlay();

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}

	// spawn the UI widget and add it to the viewport
	VehicleUI = CreateWidget<UCarSampleUI>(this, VehicleUIClass);

	check(VehicleUI);

	VehicleUI->AddToViewport();
}

void ACarSamplePlayerController::Tick(float Delta)
{
	Super::Tick(Delta);

	if (IsValid(VehiclePawn) && IsValid(VehicleUI))
	{
		VehicleUI->UpdateSpeed(VehiclePawn->GetChaosVehicleMovement()->GetForwardSpeed());
		VehicleUI->UpdateGear(VehiclePawn->GetChaosVehicleMovement()->GetCurrentGear());
	}
}

void ACarSamplePlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// get a pointer to the controlled pawn
	VehiclePawn = CastChecked<ACarSamplePawn>(InPawn);
}
