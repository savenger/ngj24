// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageableComponent.h"
#include "CarSample/CarSampleOffroadCar.h"


// Sets default values for this component's properties
UDamageableComponent::UDamageableComponent() : MaxLife(0), CurrentLife(0)
{
}


// Called when the game starts
void UDamageableComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentLife = MaxLife;
}


void UDamageableComponent::TakeDamage(int32 DamageAmount)
{
	
	CurrentLife = FMath::Clamp(CurrentLife, 0, CurrentLife - static_cast<float>(DamageAmount));
	if(DamageAmount != 0)
	{
		OnDamageNormalChange.Broadcast(CurrentLife / MaxLife);
	}
	
	if (CurrentLife == 0)
	{
		// Print on screen player dead
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Player is dead"));
		
		if (OnDamageableDeath.IsBound())
		{

			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Player Death"));
			OnDamageableDeath.Broadcast(0);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No subscribers to OnDamageableDeath"));
		}
		
	}
}


