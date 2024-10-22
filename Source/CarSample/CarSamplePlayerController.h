// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CarSamplePlayerController.generated.h"

class UInputMappingContext;
class ACarSamplePawn;
class UCarSampleUI;

/**
 *  Vehicle Player Controller class
 *  Handles input mapping and user interface
 */
UCLASS(abstract)
class CARSAMPLE_API ACarSamplePlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;


	/** Type of the UI to spawn */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = UI)
	TSubclassOf<UCarSampleUI> VehicleUIClass;

	/** Pointer to the UI widget */
	//TObjectPtr<UCarSampleUI> VehicleUI;

	// Begin Actor interface
protected:
	FTimerHandle LocalPlayerTimerHandle;
	UFUNCTION()
	void TimerFunctionLocalPlayer();

	virtual void BeginPlay() override;

public:

	/** Pointer to the controlled vehicle pawn */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<ACarSamplePawn> VehiclePawn;
	
	virtual void Tick(float Delta) override;

	// End Actor interface

	// Begin PlayerController interface
protected:

	virtual void OnPossess(APawn* InPawn) override;

	// End PlayerController interface
};
