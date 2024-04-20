// Fill out your copyright notice in the Description page of Project Settings.


#include "UIEndGameWidget.h"




void UUIEndGameWidget::OpenEndScreen(bool bRightIsWinner)
{
	if (bRightIsWinner)
	{
		RightPlayerScreen_Image->SetBrushFromTexture(WinImage);
		LeftPlayerScreen_Image->SetBrushFromTexture(LooseImage);
	}
	else
	{
		RightPlayerScreen_Image->SetBrushFromTexture(LooseImage);
		LeftPlayerScreen_Image->SetBrushFromTexture(WinImage);
	}
}
