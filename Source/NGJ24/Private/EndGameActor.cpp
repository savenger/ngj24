// Fill out your copyright notice in the Description page of Project Settings.


#include "EndGameActor.h"
#include "Blueprint/UserWidget.h"
#include "UIEndGameWidget.h"
#include "UnrealEngine.h"
#include "CarSample/CarSampleOffroadCar.h"
#include <Kismet/GameplayStatics.h>


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
	

	SetOnEndGameEvent();
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

void AEndGameActor::SetOnEndGameEvent()
{
	if (DamageableComponents.Num() == 2)
		return;
	// Get all component of type DamageableComponent
    // and subscribe to the event OnDamage
	TArray<APlayerController*> PlayerList;
	PlayerList.Push(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	PlayerList.Push(UGameplayStatics::GetPlayerController(GetWorld(), 1));
	for (APlayerController* PlayerController : PlayerList)
	{
		auto Pawn = PlayerController->GetPawn();
		if (IsValid(Pawn))
		{
			if (ACarSampleOffroadCar* OffroadCarPawn = Cast<ACarSampleOffroadCar>(PlayerController->GetPawn()))
			{
				if (UDamageableComponent* DamageComponent = OffroadCarPawn->DamageableComponent)
				{
					DamageableComponents.Push(DamageComponent);
					DamageComponent->OnDamageableDeath.AddUniqueDynamic(this, &AEndGameActor::OpenEndGamePanel);
				}

			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Pawn is not a CarSampleOffroadCar on %s"), *PlayerController->GetName());

			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Pawn is null on %s calling it again in X seconds"), *PlayerController->GetName());
			GetWorld()->GetTimerManager().SetTimer(LocalPlayerTimerHandle, this, &AEndGameActor::SetOnEndGameEvent, 0.5, false);
			break;
		}
	
	}
}

