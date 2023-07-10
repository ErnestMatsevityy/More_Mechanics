// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovableUnit.generated.h"

UCLASS()
class MORE_MECHANICS_API AMovableUnit : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovableUnit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float Alpha;

	float LiftTime;

	float LiftHeight;

	float MovementOffset;

	float ElapsedTime = 0.0f;

	float TargetHeight = 0.0f;

	UPROPERTY(EditAnywhere)
	float MovementSpeed = 100.0f;

	UPROPERTY(EditAnywhere)
	FVector DistanceUP = FVector(0, 0, 300);

	UPROPERTY(EditDefaultsOnly, Category = "Stairs")
	float InitialHeight = 0.0f;

	float DistanceValue;
	float RangeTriggerValue;
};
