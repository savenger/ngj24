// Copyright Epic Games, Inc. All Rights Reserved.

#include "CarSampleWheelFront.h"
#include "UObject/ConstructorHelpers.h"

UCarSampleWheelFront::UCarSampleWheelFront()
{
	AxleType = EAxleType::Front;
	bAffectedBySteering = true;
	MaxSteerAngle = 40.f;
}