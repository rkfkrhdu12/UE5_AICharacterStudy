// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/State/GameplayStateBase.h"

#include "Character/CharacterBase.h"
#include "Character/State/StateSystemComponent.h"

UGameplayStateBase::UGameplayStateBase()
{
}

void UGameplayStateBase::BeginPlay(ACharacterBase* Character)
{
	if (!Character) return;

	_Character = Character;
	if (!_Character) return;

	_Character->GetStateComponent()->OnStateChanged.AddDynamic(this, &UGameplayStateBase::OnChangeState);
}

bool UGameplayStateBase::IsTransition(const FName& TransStateName) const
{
	return _EnableTransitionNames.Contains(TransStateName) && !_IgnoreTransitionNames.Contains(TransStateName);
}

void UGameplayStateBase::OnEnter()
{
	Enter();
}

void UGameplayStateBase::OnExit()
{
	Exit();
}

void UGameplayStateBase::OnChangeState(uint8 State)
{
	ChangeState(State);
}
