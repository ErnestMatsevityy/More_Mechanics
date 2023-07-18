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

	StartLocation = GetActorLocation();



}

// Called every frame
void AMovableUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UCheckingDistance* CheckingDistanceComponent = FindComponentByClass<UCheckingDistance>();
	DistanceValue = CheckingDistanceComponent->Distance;
	RangeTriggerValue = CheckingDistanceComponent->RangeTrigger;
	
	//if (DistanceValue <= RangeTriggerValue)
	//{
	//	ElapsedTime += DeltaTime;

	//	LiftTime = 0.3f; // Час підйому актора
	//	LiftHeight = 110.0f; // Висота підйому актора
	//	Alpha = FMath::Clamp(ElapsedTime / LiftTime, 0.0f, 1.0f);
	//	MovementOffset = FMath::Lerp(InitialHeight, InitialHeight + LiftHeight, Alpha);

	//	FVector NewLocation = GetActorLocation();
	//	NewLocation.Z = MovementOffset;
	//	SetActorLocation(NewLocation);

	//	if (Alpha >= 1.0f)
	//	{
	//		// Виконуємо дії, коли підйом завершено
	//	}
	//}

	// If the distance is less than the threshold, move this actor to the target location.
	if (DistanceValue <= RangeTriggerValue) 
	{
		DistanceUP = GetActorLocation() + FVector(0, 0, MoveUP);
		SetActorLocation(DistanceUP);
	}

	// If the distance is greater than the threshold, move this actor back to its original location.
	else 
	{
		SetActorLocation(StartLocation);
	}

	// Move this actor smoothly between the two locations.
	float lerpFactor = FMath::Clamp(DistanceValue / RangeTriggerValue, 0.0f, 1.0f);
	SetActorLocation(FMath::Lerp(DistanceUP, StartLocation, lerpFactor));

	UE_LOG(LogTemp, Warning, TEXT("DistanceValue: %f"), DistanceValue);
	UE_LOG(LogTemp, Warning, TEXT("DistanceUP: %s"), *DistanceUP.ToString());
	UE_LOG(LogTemp, Warning, TEXT("RangeTriggerValue: %f"), RangeTriggerValue);
	UE_LOG(LogTemp, Warning, TEXT("------------"), DistanceValue);

	//FVector actorLocation = GetActorLocation();
	//float zOffset = 10.0f;
	//FVector newLocation = actorLocation + FVector(0, 0, zOffset);

	//UE_LOG(LogTemp, Warning, TEXT("New location: %s"), *newLocation.ToString());
}