// Fill out your copyright notice in the Description page of Project Settings.


#include "MovableUnit.h"
#include "CheckingDistance.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AMovableUnit::AMovableUnit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovableUnit::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();

	DistanceUP = StartLocation + FVector(0, 0, MoveUP);
}

// Called every frame
void AMovableUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GetDistance();
		
	if (DistanceValue <= RangeTriggerValue) // If the distance is less than the threshold, move this actor to the target location.
	{
		MoveUp(DeltaTime);
	}
	else // If the distance is greater than the threshold, move this actor back to its original location.
	{
		MoveDown(DeltaTime);
	}

	clampTime = FMath::Clamp(LiftingTime, 0.0f, 1.0f);
	SetActorLocation(FMath::Lerp(StartLocation, DistanceUP, clampTime));
}

void AMovableUnit::GetDistance()
{
	UCheckingDistance* CheckingDistanceComponent = FindComponentByClass<UCheckingDistance>();
	DistanceValue = CheckingDistanceComponent->Distance;
	RangeTriggerValue = CheckingDistanceComponent->RangeTrigger;
}

void AMovableUnit::MoveUp(float DeltaTime)
{
	Time += DeltaTime;
	LiftingTime = LiftingTime + (Time * SpeedUp);
	if (LiftingTime >= 1.0f)
	{
		LiftingTime = 1.0f;
		Time = 0.0f;
	}

	SetActorLocation(DistanceUP);
}

void AMovableUnit::MoveDown(float DeltaTime)
{
	Time -= DeltaTime;
	LiftingTime = LiftingTime + (Time * SpeedDown);
	if (LiftingTime <= 0.0f)
	{
		LiftingTime = 0.0f;
		Time = 0.0f;
	}

	SetActorLocation(StartLocation);
}