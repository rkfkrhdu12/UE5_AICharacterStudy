// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/State/GameplayStateBase.h"

#include "Character/CharacterBase.h"

UGameplayStateBase::UGameplayStateBase()
{
}

void UGameplayStateBase::BeginPlay(ACharacterBase* Character)
{
	if (!Character) return;

	_Character = Character;
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
