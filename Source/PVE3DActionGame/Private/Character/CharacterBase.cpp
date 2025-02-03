// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterBase.h"

#include "Character/State/StateSystemComponent.h"
#include "Character/Action/ActionSystemComponent.h"
#include "Character/Attribute/AttributeSystemComponent.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

bool ACharacterBase::BeginPlayComponents()
{
	bool ReturnValue = true;

	if (StateSystem)
	{
		_StateSystemComponent = NewObject<UStateSystemComponent>(this, StateSystem);
		_StateSystemComponent->RegisterComponent();
	}

	// TODO : InputSystem

	//
	
	if (ActionSystem)
	{
		_ActionSystemComponent = NewObject<UActionSystemComponent>(this, ActionSystem);
		_ActionSystemComponent->RegisterComponent();
	}

	if (AttributeSystem)
	{
		_AttributeSystemComponent = NewObject<UAttributeSystemComponent>(this, AttributeSystem);
		_AttributeSystemComponent->RegisterComponent();
	}

	return ReturnValue;
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();

	BeginPlayComponents();
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

