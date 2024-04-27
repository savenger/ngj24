// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonGameViewportClient.h"

#include "CommonGameViewportMultiplayer.generated.h"


/**
 * 
 */
UCLASS()
class GAMEVIEWPORTLOCALMULTIPLAYER_API UCommonGameViewportMultiplayer : public UCommonGameViewportClient
{
	GENERATED_BODY()

	virtual void RemapControllerInput(FInputKeyEventArgs& InOutKeyEvent) override;
	
};
