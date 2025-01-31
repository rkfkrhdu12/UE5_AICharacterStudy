// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorComponentBase.h"

#include "Character/CharacterBase.h"

// Sets default values for this component's properties
UActorComponentBase::UActorComponentBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	_Character = Cast<ACharacterBase>(GetOwner());
}

// Called when the game starts
void UActorComponentBase::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UActorComponentBase::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
