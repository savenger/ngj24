// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Engine/Texture2D.h"

#include <Components/Image.h>
#include "UIEndGameWidget.generated.h"


/**
 * 
 */
UCLASS()
class NGJ24_API UUIEndGameWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		TObjectPtr<UImage> LeftPlayerScreen_Image;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		TObjectPtr<UImage> RightPlayerScreen_Image;

	UPROPERTY(EditDefaultsOnly)
		TObjectPtr<UTexture2D> WinImage;

	UPROPERTY(EditDefaultsOnly)
		TObjectPtr<UTexture2D> LooseImage;

	void OpenEndScreen(bool bRightIsWinner);
};
