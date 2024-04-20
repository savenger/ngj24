// Copyright Epic Games, Inc. All Rights Reserved.

#include "CarSampleWheelRear.h"
#include "UObject/ConstructorHelpers.h"

UCarSampleWheelRear::UCarSampleWheelRear()
{
	AxleType = EAxleType::Rear;
	bTractionControlEnabled = true;
	bAffectedByHandbrake = true;
	bAffectedByEngine = true;
}