// Fill out your copyright notice in the Description page of Project Settings.


#include "EndGameActor.h"
#include "Blueprint/UserWidget.h"
#include "UIEndGameWidget.h"

// Sets default values
AEndGameActor::AEndGameActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEndGameActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEndGameActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEndGameActor::OpenEndGamePanel(int32 PlayerIndex)
{
	bool bRightIsWinner = PlayerIndex == 0 ? true : false;

	if (IsValid(EndGameWidget))
	{

		UUserWidget* UserWidget = CreateWidget(GetWorld(), EndGameWidget, FName("GameOverPanel"));
	
		if (UserWidget != nullptr)
		{
			// set the correct controller 
			UserWidget->AddToViewport(0);
		}

		if (UUIEndGameWidget* EndGameUI = Cast<UUIEndGameWidget>(UserWidget))
		{
			EndGameUI->OpenEndScreen(bRightIsWinner);
		}
	}
	else
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("EndGame widget not set"));
	}
}

