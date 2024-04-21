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
	
	// Get all component of type DamageableComponent
	// and subscribe to the event OnDamage
	TArray<APlayerController*> PlayerList;
	PlayerList.Push(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	PlayerList.Push(UGameplayStatics::GetPlayerController(GetWorld(), 1));
	for (APlayerController* PlayerController : PlayerList)
	{
		if (UDamageableComponent* DamageComponent = Cast<ACarSampleOffroadCar>(PlayerController->GetPawn())->DamageableComponent)
		{
			DamageableComponents.Push(DamageComponent);
			DamageComponent->OnDamageableDeath.AddUniqueDynamic(this, &AEndGameActor::OpenEndGamePanel);
		}
	}

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

