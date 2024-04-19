// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CarSamplePawn.h"
#include "CarSampleSportsCar.generated.h"

/**
 *  Sports car wheeled vehicle implementation
 */
UCLASS(abstract)
class CARSAMPLE_API ACarSampleSportsCar : public ACarSamplePawn
{
	GENERATED_BODY()
	
public:

	ACarSampleSportsCar();
};
