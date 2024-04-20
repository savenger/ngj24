// Copyright Epic Games, Inc. All Rights Reserved.


#include "CarSamplePlayerController.h"
#include "CarSamplePawn.h"
#include "CarSampleUI.h"
#include "EnhancedInputSubsystems.h"
#include "ChaosWheeledVehicleMovementComponent.h"

void ACarSamplePlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto* LocalPlayer = GetLocalPlayer();
	if( LocalPlayer)
	{
		UE_LOG(LogTemp, Warning, TEXT("Local Player: %s"), *LocalPlayer->GetNickname());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Local Player null"))
		return;
	}
	auto* AdvancedInputComponent = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	// get the enhanced input subsystem
	if (AdvancedInputComponent)
	{
		// add the mapping context so we get controls
		AdvancedInputComponent->AddMappingContext(InputMappingContext, 0);
	}

	// spawn the UI widget and add it to the viewport
	//VehicleUI = CreateWidget<UCarSampleUI>(this, VehicleUIClass);

	//check(VehicleUI);

	//VehicleUI->AddToViewport();
}

void ACarSamplePlayerController::Tick(float Delta)
{
	Super::Tick(Delta);

	// if (IsValid(VehiclePawn) && IsValid(VehicleUI))
	// {
	// 	VehicleUI->UpdateSpeed(VehiclePawn->GetChaosVehicleMovement()->GetForwardSpeed());
	// 	VehicleUI->UpdateGear(VehiclePawn->GetChaosVehicleMovement()->GetCurrentGear());
	// }
}

void ACarSamplePlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// get a pointer to the controlled pawn
	VehiclePawn = CastChecked<ACarSamplePawn>(InPawn);
}
