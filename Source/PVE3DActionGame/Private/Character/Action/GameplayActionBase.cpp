// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Action/GameplayActionBase.h"

#include "Character/CharacterBase.h"
#include "Character/Action/ActionSystemComponent.h"
#include "Character/State/StateSystemComponent.h"

// Sets default values for this component's properties
UGameplayActionBase::UGameplayActionBase()
{
	
}

void UGameplayActionBase::OnBeginPlay(ACharacterBase* Character)
{
	_Character = Character;
	if (!_Character) { UE_LOG(LogTemp, Log, TEXT("%s(Action)'s Character Is Null"), *GetActionName().ToString()); return; }
	
	_Mesh = _Character->GetMesh();
	if (!_Mesh) { UE_LOG(LogTemp, Log, TEXT("%s(Action)'s Mesh Is Null"), *GetActionName().ToString()); return; }

	_AnimInstance = _Mesh->GetAnimInstance();
	if (!_AnimInstance) { UE_LOG(LogTemp, Log, TEXT("%s(Action)'s AnimInstance Is Null"), *GetActionName().ToString()); return;}

	_ActionSystem = _Character->GetActionComponent();
	if (!_ActionSystem) {  UE_LOG(LogTemp, Log, TEXT("%s(Action)'s _ActionSystem Is Null"), *GetActionName().ToString()); return; }

	if (_Character)
		_Character->GetStateComponent()->OnStateChanged.AddDynamic(this, &UGameplayActionBase::OnReciveStateChange);
	
	BeginPlay(Character);
}

void UGameplayActionBase::OnEnter()
{
	_IsActive = true;
	
	Enter();
}

void UGameplayActionBase::OnExit()
{
	if (_IsActive)
	{
		_IsActive = false;
	
		Exit();
	}
}

void UGameplayActionBase::OnBreak()
{
	if (_IsActive)
	{
		_IsActive = false;
		
		Break();
	}
}

void UGameplayActionBase::OnReciveStateChange(uint8 State)
{
	ReciveStateChange(State);
}


