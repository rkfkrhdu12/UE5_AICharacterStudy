// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/State/StateSystemComponent.h"

#include "Character/CharacterBase.h"

// Sets default values for this component's properties
UStateSystemComponent::UStateSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStateSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Cyan, TEXT("StateSystem Activate"));
	
}


// Called every frame
void UStateSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

