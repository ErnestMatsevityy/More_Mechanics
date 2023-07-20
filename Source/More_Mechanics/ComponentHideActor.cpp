// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponentHideActor.h"
#include "Portal.h"

// Sets default values for this component's properties
UComponentHideActor::UComponentHideActor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UComponentHideActor::BeginPlay()
{
	Super::BeginPlay();


	//PortalActor = Cast<APortal>(GetOwner());
	//HideOnOff = PortalActor->HideActor;
}


// Called every frame
void UComponentHideActor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	
	 


	
}

