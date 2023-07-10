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
	
	InitialHeight = GetActorLocation().Z;
	TargetHeight = InitialHeight;
}

// Called every frame
void AMovableUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UCheckingDistance* CheckingDistanceComponent = FindComponentByClass<UCheckingDistance>();
	DistanceValue = CheckingDistanceComponent->Distance;
	RangeTriggerValue = CheckingDistanceComponent->RangeTrigger;
	
	if (DistanceValue <= RangeTriggerValue)
	{
		ElapsedTime += DeltaTime;

		LiftTime = 0.3f; // Час підйому актора
		LiftHeight = 110.0f; // Висота підйому актора
		Alpha = FMath::Clamp(ElapsedTime / LiftTime, 0.0f, 1.0f);
		MovementOffset = FMath::Lerp(InitialHeight, InitialHeight + LiftHeight, Alpha);

		FVector NewLocation = GetActorLocation();
		NewLocation.Z = MovementOffset;
		SetActorLocation(NewLocation);

		if (Alpha >= 1.0f)
		{
			// Виконуємо дії, коли підйом завершено
		}
	}
}