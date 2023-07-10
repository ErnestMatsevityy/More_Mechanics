// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Stairs_Lifts.generated.h"

UCLASS()
class MORE_MECHANICS_API AStairs_Lifts : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStairs_Lifts();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	//void ChangeStrairsLocation(float DeltaTime);

	void CheckingDistance();

	FVector Here;

	FVector PlayerLocationValue;

	float MovementOffset;

	bool OneTime = false;

	float Distance;

	UPROPERTY(EditAnywhere)
	float RangeTrigger = 10;

	UPROPERTY(EditAnywhere)
	float MovementSpeed = 100.0f;

	UPROPERTY(EditAnywhere)
	FVector DistanceUP = FVector(0, 0, 300);

	UPROPERTY(EditDefaultsOnly, Category = "Stairs")
	float InitialHeight = 0.0f;

	float ElapsedTime = 0.0f;
	float TargetHeight = 0.0f;

};
