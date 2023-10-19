// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector currentLocation = GetActorLocation();

	currentLocation += PlatformVelocity * DeltaTime;

	SetActorLocation(currentLocation);

	float distanceMoved = FVector::Dist(currentLocation, StartLocation);

	if (distanceMoved >= PlatformDistance)
	{
		UE_LOG(LogTemp, Display, TEXT("%f"), distanceMoved - PlatformDistance);
		FVector moveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + moveDirection * PlatformDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	//FRotator NewRotation = GetActorRotation() + PlatformRotationVelocity * DeltaTime;
	//SetActorRotation(NewRotation);
	AddActorLocalRotation(PlatformRotationVelocity * DeltaTime);
}

