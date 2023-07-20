// Fill out your copyright notice in the Description page of Project Settings.


#include "Component_HideEnableDisableByTag.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SceneComponent.h" // Для роботи з компонентами USceneComponent
#include "Components/StaticMeshComponent.h" // Для роботи з компонентами UStaticMeshComponent

// Sets default values for this component's properties
UComponent_HideEnableDisableByTag::UComponent_HideEnableDisableByTag()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
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

    SearchByTag();
}

void UComponent_HideEnableDisableByTag::SearchByTag()
{
    for (AActor* Actor : FoundActors)
    {
        MeshComponent = Actor->FindComponentByClass<UStaticMeshComponent>();
        CollisionComponent = Actor->FindComponentByClass<UPrimitiveComponent>();

        if (HideActor)
        {
            Disable();
        }
        else
        {
            Enable();
        }
    }
}

void UComponent_HideEnableDisableByTag::Disable()
{
    MeshComponent->SetVisibility(false); // Приховати графічний компонент
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void UComponent_HideEnableDisableByTag::Enable()
{
    MeshComponent->SetVisibility(true); // Приховати графічний компонент
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

