// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CarSamplePawn.h"
#include "CarSampleOffroadCar.generated.h"

/**
 *  Offroad car wheeled vehicle implementation
 */

class UDamageableComponent;
UCLASS(abstract)
class CARSAMPLE_API ACarSampleOffroadCar : public ACarSamplePawn
{

private:
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
	virtual void BeginPlay() override;
	
	/* player index */
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	int32 CarOffroadPlayerIndex;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Damage, meta = (AllowPrivateAccess = "true"))
	UDamageableComponent* DamageableComponent;

    ACarSampleOffroadCar();
};
