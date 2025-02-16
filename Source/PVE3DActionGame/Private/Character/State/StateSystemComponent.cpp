// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/State/StateSystemComponent.h"

#include "Character/CharacterBase.h"
#include "Character/Input/InputSystemComponent.h"
#include "Character/State/GameplayStateBase.h"

// Sets default values for this component's properties
UStateSystemComponent::UStateSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UStateSystemComponent::BeginPlayComponent()
{
	Super::BeginPlayComponent();
	
	if (_Character)
		_Character->GetInputComponent()->OnInputRecive.AddDynamic(this, &UStateSystemComponent::ReciveInputKey);


	FString msg = FString::Printf(TEXT("CurState : %s"), *_States[_CurrentIndex]->GetStateName().ToString());
	GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Cyan, msg);
}

void UStateSystemComponent::ChangeState(uint8 StateType)
{
	if (!_States.Num() || !_StateNames.Num()) return;

	_ChangeIndex = StateType;

	UGameplayStateBase* CurrentState = _States[_CurrentIndex];
	UGameplayStateBase* ChangedState = _States[_ChangeIndex];
	if (!CurrentState && !ChangedState) return;

	FName ChangedTypeName = _StateNames[_ChangeIndex];

	if (CurrentState->IsTransition(ChangedTypeName))
	{
		// 바꿀 상태로 이동 가능함.
		CurrentState->OnExit();
		ChangedState->OnEnter();

		_PrevIndex = _CurrentIndex;
		_CurrentIndex = _ChangeIndex;
		
		FString msg = FString::Printf(TEXT("CurState : %s"), *_States[_CurrentIndex]->GetStateName().ToString());
		GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Cyan, msg);
		
		OnStateChanged.Broadcast(_CurrentIndex);
	}
}

void UStateSystemComponent::ChangeState(ECharacterState StateType)
{
	ChangeState(static_cast<uint8>(StateType));
}

void UStateSystemComponent::ReciveInputKey_Implementation(uint8 InputType)
{
	switch (const ECharacterInput CurrentInput = static_cast<ECharacterInput>(InputType))
	{
	case ECharacterInput::Attack: ChangeState(ECharacterState::Attack);
		break;
	case ECharacterInput::Dodge: ChangeState(ECharacterState::Dodge);
		break;
	}
}

// Called when the game starts
void UStateSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	if (StateCount)
	{
		for (uint8 index = 0; index != StateCount; ++index)
		{
			ECharacterState Type = static_cast<ECharacterState>(index);
			if (UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("ECharacterState"), true))
			{
				FString TypeString = EnumPtr->GetValueAsString(Type);
				if (TypeString.IsEmpty()) continue;

				int StartIndex = TypeString.Find("::") + 2;

				FName Name = FName(*TypeString.Mid(StartIndex, TypeString.Len() - StartIndex));
				if (Name.IsNone()) continue;

				_StateNames.Add(index, Name);
				_NameStates.Add(Name, index);
			}
		}
	}

	if (States.Num())
	{
		for (TSubclassOf<UGameplayStateBase> Element : States)
		{
			UGameplayStateBase* NewState = NewObject<UGameplayStateBase>(this, Element);
			if (_NameStates.Contains(NewState->GetStateName()))
			{
				NewState->BeginPlay(_Character);
				
				uint8 CurIndex = _NameStates[NewState->GetStateName()];
				_States.Add(CurIndex, NewState);
			}
		}
	}

	for (uint8 i = static_cast<uint8>(ECharacterState::Idle); i != static_cast<uint8>(ECharacterState::LAST); ++i)
	{
		if (_States.Contains(i))
		{
			UE_LOG(LogTemp, Log, TEXT("StateSystem(%s) : %hd State's Name %s"), *GetName(), i,
			       *_States[i]->GetStateName().ToString());
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("StateSystem(%s) : %hd Index Not Found"), *GetName(), i);
		}
	}
}


// Called every frame
void UStateSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
