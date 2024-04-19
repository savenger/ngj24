// Copyright Epic Games, Inc. All Rights Reserved.

#include "CarSampleGameMode.h"
#include "CarSamplePlayerController.h"

ACarSampleGameMode::ACarSampleGameMode()
{
	PlayerControllerClass = ACarSamplePlayerController::StaticClass();
}
