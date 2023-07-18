// Fill out your copyright notice in the Description page of Project Settings.


#include "MovableUnit.h"
//#include "GameFramework/Actor.h"
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

	DistanceUP = GetActorLocation() + FVector(0, 0, MoveUP);
}

// Called every frame
void AMovableUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UCheckingDistance* CheckingDistanceComponent = FindComponentByClass<UCheckingDistance>();
	DistanceValue = CheckingDistanceComponent->Distance;
	RangeTriggerValue = CheckingDistanceComponent->RangeTrigger;

	// If the distance is less than the threshold, move this actor to the target location.
	if (DistanceValue <= RangeTriggerValue)
	{
		MoveUp(DeltaTime);
	}

	// If the distance is greater than the threshold, move this actor back to its original location.
	else
	{
		MoveDown(DeltaTime);
	}

	// Move this actor smoothly between the two locations.
	SetActorLocation(FMath::Lerp(StartLocation, DistanceUP, LiftingTime));
}

void AMovableUnit::MoveUp(float DeltaTime)
{
	SetActorLocation(DistanceUP);

	Time += DeltaTime;
	LiftingTime = LiftingTime + (Time * SpeedUp);
	if (LiftingTime >= 1.0f)
	{
		LiftingTime = 1.0f;
		Time = 0.0f;
	}
}

void AMovableUnit::MoveDown(float DeltaTime)
{
	SetActorLocation(StartLocation);

	Time -= DeltaTime;
	LiftingTime = LiftingTime + (Time * SpeedDown);
	if (LiftingTime <= 0.0f)
	{
		LiftingTime = 0.0f;
		Time = 0.0f;
	}
}