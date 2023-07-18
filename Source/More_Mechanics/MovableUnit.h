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

	UPROPERTY(EditAnyWhere, Category = "Stairs")
	float MoveUP;

private:

	void MoveUp(float DeltaTime);

	void MoveDown(float DeltaTime);


	FVector StartLocation;

	FVector DistanceUP;


	float Time;

	float LiftingTime = 0.0f;


	UPROPERTY(EditAnyWhere, Category = "Move")
	float SpeedUp = 0.9;

	UPROPERTY(EditAnyWhere, Category = "Move")
	float SpeedDown = 0.25;

	UPROPERTY(EditDefaultsOnly, Category = "Stairs")
	float InitialHeight = 0.0f;

	float DistanceValue;

	UPROPERTY(EditAnyWhere, Category = "Stairs")
	float RangeTriggerValue;
};
