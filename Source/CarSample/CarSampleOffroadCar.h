// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CarSamplePawn.h"
#include "CarSampleOffroadCar.generated.h"

/**
 *  Offroad car wheeled vehicle implementation
 */
UCLASS(abstract)
class CARSAMPLE_API ACarSampleOffroadCar : public ACarSamplePawn
{
	GENERATED_BODY()
	
	/** Chassis static mesh */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Meshes, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Chassis;

	/** FL Tire static mesh */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Meshes, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TireFrontLeft;

	/** FR Tire static mesh */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Meshes, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TireFrontRight;

	/** RL Tire static mesh */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Meshes, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TireRearLeft;

	/** RR Tire static mesh */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Meshes, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TireRearRight;

public:

	ACarSampleOffroadCar();
};
