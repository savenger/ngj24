// Copyright Epic Games, Inc. All Rights Reserved.

#include "CarSampleWheelFront.h"
#include "UObject/ConstructorHelpers.h"

UCarSampleWheelFront::UCarSampleWheelFront()
{
	AxleType = EAxleType::Front;
	bAffectedBySteering = true;
	bTractionControlEnabled = true;
	MaxSteerAngle = 40.f;

	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0, FColor::Yellow, TEXT("Front"));
}