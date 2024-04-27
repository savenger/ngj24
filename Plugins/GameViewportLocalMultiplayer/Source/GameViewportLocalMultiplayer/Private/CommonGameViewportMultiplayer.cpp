// Fill out your copyright notice in the Description page of Project Settings.


#include "CommonGameViewportMultiplayer.h"

#include "Engine/GameInstance.h"
#include "Engine/LocalPlayer.h"
#include "UnrealClient.h"
#include "InputKeyEventArgs.h"
#include "GameMapsSettings.h"

class UGameInstance;

static TAutoConsoleVariable<bool> CVarRemapDeviceIdForOffsetPlayerGamepadIds(
	TEXT("input.bRemapDeviceIdForOffsetPlayerGamepadIds"),
	true,
	TEXT("If true, then when bOffsetPlayerGamepadIds is true we will create a new Input Device Id\n")
	TEXT("as needed for the next local player. This fixes the behavior in split screen.\n")
	TEXT("Note: This CVar will be removed in a future release, this is a temporary wrapper for bug fix behavior."),
	ECVF_Default);

void UCommonGameViewportMultiplayer::RemapControllerInput(FInputKeyEventArgs& InOutKeyEvent)
{
	const int32 NumLocalPlayers = World ? World->GetGameInstance()->GetNumLocalPlayers() : 0;

	if (NumLocalPlayers > 1 && InOutKeyEvent.Key.IsGamepadKey() && GetDefault<UGameMapsSettings>()->bOffsetPlayerGamepadIds)
	{
		// Temp cvar in case this change somehow breaks input for any split screen games.
		if (CVarRemapDeviceIdForOffsetPlayerGamepadIds.GetValueOnAnyThread())
		{
			const TArray<ULocalPlayer*>& CurrentLocalPlayers = World->GetGameInstance()->GetLocalPlayers();
			if (CurrentLocalPlayers.IsValidIndex(InOutKeyEvent.ControllerId) && CurrentLocalPlayers.IsValidIndex(InOutKeyEvent.ControllerId + 1))
			{
				const FPlatformUserId DesiredPlatformUser = CurrentLocalPlayers[InOutKeyEvent.ControllerId + 1]->GetPlatformUserId();

				IPlatformInputDeviceMapper& DeviceMapper = IPlatformInputDeviceMapper::Get();

				// Check for if this FPlatformUserID already has a primary input device ID. If it does, we can use that
				FInputDeviceId DesiredInputDeviceId = DeviceMapper.GetPrimaryInputDeviceForUser(DesiredPlatformUser);
				if (!DesiredInputDeviceId.IsValid())
				{
					// Otherwise we need to create a new "Fake" input device ID...
					DesiredInputDeviceId = DeviceMapper.AllocateNewInputDeviceId();

					// ...  and map it to our desired platform user so that the PlayerController knows it that this is associated with the local player
					DeviceMapper.Internal_MapInputDeviceToUser(DesiredInputDeviceId, DesiredPlatformUser, EInputDeviceConnectionState::Connected);
				}

				// Say that this input event is from the other local player's input device!
				InOutKeyEvent.InputDevice = DesiredInputDeviceId;
			}
		}

		// We still want to increment the controller ID in case there is any legacy code listening for it
		InOutKeyEvent.ControllerId++;
	}
	else if (InOutKeyEvent.Viewport->IsPlayInEditorViewport() && InOutKeyEvent.Key.IsGamepadKey())
	{
		GEngine->RemapGamepadControllerIdForPIE(this, InOutKeyEvent.ControllerId);
	}
}
