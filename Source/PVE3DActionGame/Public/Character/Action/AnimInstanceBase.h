// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimInstanceBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAnimationNotify, FName, Name);

/**
 * 
 */
UCLASS()
class PVE3DACTIONGAME_API UAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintAssignable)
	FAnimationNotify OnAnimationNotify;

	UFUNCTION(BlueprintCallable)
	void OnNotifyBroadcast(const FString& Name);
};
