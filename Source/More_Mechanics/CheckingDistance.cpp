// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckingDistance.h"
#include "MovableUnit.generated.h"
#include "Kismet/GameplayStatics.h"
#include <Perception/AIPerceptionComponent.h>

// Sets default values for this component's properties
UCheckingDistance::UCheckingDistance()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCheckingDistance::BeginPlay()
{
	Super::BeginPlay();

	CurrentLocation = GetOwner()->GetActorLocation();
}


// Called every frame
void UCheckingDistance::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CheckingDistance();
}

void UCheckingDistance::CheckingDistance()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController)
	{
		PlayerLocationValue = PlayerController->GetPawn()->GetActorLocation();
	}
	Distance = FVector::Dist(CurrentLocation, PlayerLocationValue);
}