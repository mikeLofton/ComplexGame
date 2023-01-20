 // Fill out your copyright notice in the Description page of Project Settings.

#define print(text) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, text)
#define printf(text, fstring) if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, FString::Printf(TEXT(text), fstring))

#include "EncounterTriggerBox.h"
#include <DrawDebugHelpers.h>

AEncounterTriggerBox::AEncounterTriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &AEncounterTriggerBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AEncounterTriggerBox::OnOverlapEnd);

}

void AEncounterTriggerBox::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	//If OtherActer and this are not the same
	if (OtherActor && (OtherActor != this))
	{
		//Display debug message
		print("Overlap Begin");
		printf("Overlapped Actor = %", *OverlappedActor->GetName());
	}
}

void AEncounterTriggerBox::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	//If OtherActer and this are not the same
	if (OtherActor && (OtherActor != this))
	{
		//Display Debug message
		print("Overlap Ended");
		printf("Overlapped Actor = %", *OverlappedActor->GetName());
	}
}

void AEncounterTriggerBox::BeginPlay()
{
	Super::BeginPlay();

	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5); //makes the trigger box visible
}
