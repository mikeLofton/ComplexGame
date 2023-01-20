// Fill out your copyright notice in the Description page of Project Settings.


#include "EncounterBoxActor.h"
#include <Components/CapsuleComponent.h>

// Sets default values
AEncounterBoxActor::AEncounterBoxActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// declare trigger box
	TriggerBox = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Box"));
	

}

void AEncounterBoxActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void AEncounterBoxActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

// Called when the game starts or when spawned
void AEncounterBoxActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEncounterBoxActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

