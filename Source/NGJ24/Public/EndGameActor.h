// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CarSample/DamageableComponent.h"
#include "Engine/EngineTypes.h"

#include "EndGameActor.generated.h"

class UUIEndgameWidget;

UCLASS()
class NGJ24_API AEndGameActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEndGameActor();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> EndGameWidget;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TArray<UDamageableComponent*> DamageableComponents;
	
	FTimerHandle LocalPlayerTimerHandle;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void OpenEndGamePanel(int32 PlayerIndex);

	void SetOnEndGameEvent();

};
