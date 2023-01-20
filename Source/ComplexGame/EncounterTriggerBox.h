// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "EncounterTriggerBox.generated.h"

/**
 Box Trigger that starts battles when the player is overlapping its collider
 */
UCLASS()
class COMPLEXGAME_API AEncounterTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	
public:
	//Set the default values for the actor
	AEncounterTriggerBox();

	//Is called when this actor's collider and anothers start overlapping each other
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	//Is called when this actor's collider and anothers stop overlapping each other
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
