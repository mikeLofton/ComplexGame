// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create the camera arm
	CameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Arm"));
	CameraArm->SetupAttachment(RootComponent);
	CameraArm->TargetArmLength = 300.0f;
	CameraArm->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));

	//Create the camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	Camera->SetupAttachment(CameraArm);

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerCharacter::ApplyMovement(float horizontal, float vertical, float speed)
{
	FVector forward = GetActorForwardVector();
	FVector right = GetActorRightVector();

	FVector direction;
	direction = forward * vertical;
	direction += right * horizontal;
	direction.Normalize();
	AddMovementInput(direction, speed);
}

