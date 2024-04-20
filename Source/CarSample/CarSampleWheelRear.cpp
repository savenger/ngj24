// Copyright Epic Games, Inc. All Rights Reserved.

#include "CarSampleWheelRear.h"
#include "UObject/ConstructorHelpers.h"

UCarSampleWheelRear::UCarSampleWheelRear()
{
	AxleType = EAxleType::Rear;
	bTractionControlEnabled = true;
	bAffectedByHandbrake = true;
	bAffectedByEngine = true;

	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0, FColor::Yellow, TEXT("Rear"));
}