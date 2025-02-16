// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterBase.h"

#include "Character/State/StateSystemComponent.h"
#include "Character/Action/ActionSystemComponent.h"
#include "Character/Attribute/AttributeSystemComponent.h"
#include "Character/Input/InputSystemComponent.h"
#include "Character/Tag/TagSystemComponent.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

bool ACharacterBase::RegisterComponents()
{
	bool ReturnValue = true;

	if (StateSystem)
	{
		_StateSystemComponent = NewObject<UStateSystemComponent>(this, StateSystem);
		_StateSystemComponent->RegisterComponent();
	}

	if (InputSystem)
	{
		_InputSystemComponent = NewObject<UInputSystemComponent>(this, InputSystem);
		_InputSystemComponent->RegisterComponent();
	}
	
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

	if (!_TagSystemComponent)
	{
		_TagSystemComponent = NewObject<UTagSystemComponent>(this);
		_TagSystemComponent->RegisterComponent();
	}

	return ReturnValue;
}

bool ACharacterBase::StartComponents()
{
	bool ReturnValue = true;

	if (StateSystem)
	{
		_StateSystemComponent->BeginPlayComponent();
	}

	if (InputSystem)
	{
		_InputSystemComponent->BeginPlayComponent();
	}
	
	if (ActionSystem)
	{
		_ActionSystemComponent->BeginPlayComponent();
	}

	if (AttributeSystem)
	{
		_AttributeSystemComponent->BeginPlayComponent();
	}

	return ReturnValue;
}

void ACharacterBase::OnInputKey(ECharacterInput InputType)
{
	if (_InputSystemComponent)
	{
		_InputSystemComponent->OnInputRecive.Broadcast(static_cast<uint8>(InputType));
	}
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();

	RegisterComponents();

	StartComponents();
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

