// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterBase.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

bool ACharacterBase::InitializeSystem()
{
	bool ReturnValue = true;

	if (StateSystem)
	{
		_StateSystemComponent = NewObject<UStateSystemComponent>(this, StateSystem);
		
	}

	// TODO : InputSystem

	//
	
	if (ActionSystem)
	{
		_ActionSystemComponent = NewObject<UActionSystemComponent>(this, ActionSystem);
		
	}

	if (AttributeSystem)
	{
		_AttributeSystemComponent = NewObject<UAttributeSystemComponent>(this, AttributeSystem);
		
	}

	return ReturnValue;
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

