// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageableComponent.h"
#include "CarSample/CarSampleOffroadCar.h"
#include "Blueprint/UserWidget.h"


// Sets default values for this component's properties
UDamageableComponent::UDamageableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.

	// ...
}


// Called when the game starts
void UDamageableComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentLife = MaxLife;
	
}


void UDamageableComponent::TakeDamage(int32 DamageAmount)
{
	
	CurrentLife = FMath::Clamp(CurrentLife, 0, CurrentLife - DamageAmount);
	
	if (CurrentLife == 0)
	{
		// Print on screen player dead
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Player is dead"));
		
		ShowEndScreenPanel();
		
	}
}

void UDamageableComponent::ShowEndScreenPanel()
{
	AActor* PlayerOwner = GetOwner();

	ACarSampleOffroadCar* CarActor = Cast<ACarSampleOffroadCar>(PlayerOwner);

	if (IsValid(CarActor->EndGamePanel))
	{

		UUserWidget* UserWidget = CreateWidget(GetWorld(), CarActor->EndGamePanel, FName("GameOverPanel"));
	
		if (UserWidget != nullptr)
		{
			// set the correct controller 
		
			UserWidget->AddToViewport(0);
		}
	}
}

