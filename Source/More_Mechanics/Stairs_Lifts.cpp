// Fill out your copyright notice in the Description page of Project Settings.


#include "Stairs_Lifts.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"

AStairs_Lifts::AStairs_Lifts()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AStairs_Lifts::BeginPlay()
{
	Super::BeginPlay();

	Here = GetActorLocation();
	InitialHeight = GetActorLocation().Z;
	TargetHeight = InitialHeight;
}

void AStairs_Lifts::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (OneTime == false)
	{
		CheckingDistance();

		if (Distance <= RangeTrigger)
		{
			ElapsedTime += DeltaTime;

			float LiftTime = 0.3f; // Час підйому актора
			float LiftHeight = 110.0f; // Висота підйому актора
			float Alpha = FMath::Clamp(ElapsedTime / LiftTime, 0.0f, 1.0f);
			MovementOffset = FMath::Lerp(InitialHeight, InitialHeight + LiftHeight, Alpha);

			FVector NewLocation = GetActorLocation();
			NewLocation.Z = MovementOffset;
			SetActorLocation(NewLocation);

			//ChangeStrairsLocation(DeltaTime);

			if (Alpha >= 1.0f)
			{
				// Виконуємо дії, коли підйом завершено
			}
		}
	}
}

void AStairs_Lifts::CheckingDistance()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController)
	{
		PlayerLocationValue = PlayerController->GetPawn()->GetActorLocation();
	}
	Distance = FVector::Dist(Here, PlayerLocationValue);
}

//void AStairs_Lifts::ChangeStrairsLocation(float DeltaTime)
//{
//	OneTime = true;
//}