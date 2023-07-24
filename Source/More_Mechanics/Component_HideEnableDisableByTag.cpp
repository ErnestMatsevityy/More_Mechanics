// Fill out your copyright notice in the Description page of Project Settings.


#include "Component_HideEnableDisableByTag.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values for this component's properties
UComponent_HideEnableDisableByTag::UComponent_HideEnableDisableByTag()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UComponent_HideEnableDisableByTag::BeginPlay()
{
	Super::BeginPlay();

    UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName(TEXT("World1")), FoundActors);
}


// Called every frame
void UComponent_HideEnableDisableByTag::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    Start();
}

void UComponent_HideEnableDisableByTag::Start()
{
    for (AActor* Actor : FoundActors)
    {
        SearchByTag(Actor);
        Disable();

        if (HideActor)
        {
            Enable();
        }
        else
        {
            Disable();
        }
    }
}

void UComponent_HideEnableDisableByTag::SearchByTag(AActor* Actor)
{
    MeshComponent = Actor->FindComponentByClass<UStaticMeshComponent>();
    CollisionComponent = Actor->FindComponentByClass<UPrimitiveComponent>();
}

void UComponent_HideEnableDisableByTag::Disable()
{
    //MeshComponent->SetVisibility(false);
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    HiddenGame = true;
}

void UComponent_HideEnableDisableByTag::Enable()
{
    //MeshComponent->SetVisibility(true);
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    HiddenGame = false;
}