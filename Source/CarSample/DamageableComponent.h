// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Delegates/Delegate.h>

#include "DamageableComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UDamageableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDamageableComponent();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTOnActorDeath, int32, ActorIndex);

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int32 MaxLife;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	int32 CurrentLife;
public:	

	// Function to call to apply damage
	UFUNCTION(BlueprintCallable, Category = "CustomDamage")
	void TakeDamage(int32 DamageAmount);

	// Action that gets called when the actor dies
	UPROPERTY(BlueprintAssignable, Category = "CustomDamage")
		FTOnActorDeath OnDamageableDeath;

	UFUNCTION(BlueprintCallable)
	void ShowEndScreenPanel();
};
