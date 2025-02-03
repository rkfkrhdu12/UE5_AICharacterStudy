// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/State/GameplayStateBase.h"

UGameplayStateBase::UGameplayStateBase()
{
	if (_Name != "")
	{
		_Name = GetName();
		int32 FindIndex = _Name.Find(TEXT("State"));
		if (FindIndex > 0)
		{
			int32 FindLeftIndex = _Name.Find(TEXT("_"));

			if (FindIndex > FindLeftIndex)
			{
				// UE_LOG(LogTemp, Warning, TEXT("UGameplayStateBase Name : %s"), *GetName());
				// UE_LOG(LogTemp, Warning, TEXT("UGameplayStateBase I : %d %d"), FindLeftIndex, FindIndex);
				// UE_LOG(LogTemp, Warning, TEXT("UGameplayStateBase AutoName : %s"), *GetName().Mid(FindLeftIndex + 1, FindIndex - 1 - FindLeftIndex));

				_Name = _Name.Mid(FindLeftIndex + 1, FindIndex - 1 - FindLeftIndex);
			}
		}
	}
}

void UGameplayStateBase::BeginPlay()
{
}

bool UGameplayStateBase::IsTransition(FName TransStateName) const
{
	return true;
}

void UGameplayStateBase::OnEnter()
{
}

void UGameplayStateBase::OnExit()
{
}
