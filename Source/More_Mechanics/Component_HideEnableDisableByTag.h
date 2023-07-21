// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Component_HideEnableDisableByTag.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MORE_MECHANICS_API UComponent_HideEnableDisableByTag : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UComponent_HideEnableDisableByTag();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


	TArray<AActor*> FoundActors;


	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere)
		UPrimitiveComponent* CollisionComponent;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	void SearchByTag(AActor* Actor);

	void Disable();

	void Enable();

	void Start();


	bool HiddenGame = true;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool HideActor;
};
