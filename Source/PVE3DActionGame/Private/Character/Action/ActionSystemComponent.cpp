// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Action/ActionSystemComponent.h"

#include "Character/CharacterBase.h"
#include "Character/Action/GameplayActionBase.h"
#include "Character/State/StateSystemComponent.h"

// Sets default values for this component's properties
UActionSystemComponent::UActionSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UActionSystemComponent::StartAction(FName ActionName)
{
	if (_Actions.Contains(ActionName))
		_Actions[ActionName]->OnEnter();
}

void UActionSystemComponent::EndAction(FName ActionName)
{
	if (_Actions.Contains(ActionName))
		_Actions[ActionName]->OnExit();
}

void UActionSystemComponent::ForceEndAction(FName ActionName)
{
	if (_Actions.Contains(ActionName))
		_Actions[ActionName]->OnBreak();
}

void UActionSystemComponent::OnReciveStateChange(uint8 StateType)
{
	ReciveStateChange(StateType);
}

// Called when the game starts
void UActionSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	if (Actions.Num())
	{
		for (TSubclassOf<UGameplayActionBase> Element : Actions)
		{
			if (UGameplayActionBase* NewAction = NewObject<UGameplayActionBase>(this, Element))
			{
				_Actions.Add(NewAction->GetActionName(), NewAction);
				NewAction->OnBeginPlay(_Character);
				
				UE_LOG(LogTemp, Log, TEXT("ActionSystem(%s) : Action's Name %s"), *GetName(),
					*NewAction->GetActionName().ToString());
			}
		}
	}
}

void UActionSystemComponent::BeginPlayComponent()
{
	Super::BeginPlayComponent();
	
	if (_Character)
		_Character->GetStateComponent()->OnStateChanged.AddDynamic(this, &UActionSystemComponent::OnReciveStateChange);
}


// Called every frame
void UActionSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
