// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/State/StateSystemComponent.h"

#include "Character/CharacterBase.h"
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
	if (States.Num())
	{
		for (TSubclassOf<UGameplayStateBase> Element : States)
		{
			UGameplayStateBase* NewState = NewObject<UGameplayStateBase>(this, Element);
			_States.Add(NewState);
		}
	}
}


// Called when the game starts
void UStateSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	BeginPlayComponent();

	UE_LOG(LogTemp, Warning, TEXT("UStateSystemComponent Activate"));

	for (UGameplayStateBase* Element : _States)
	{
		UE_LOG(LogTemp, Warning, TEXT("UStateSystemComponent State : %s"), *Element->GetStateName());
	}
}


// Called every frame
void UStateSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
