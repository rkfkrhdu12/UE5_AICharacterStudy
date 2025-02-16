// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponentBase.h"
#include "GameplayTagContainer.h"
#include "TagSystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class PVE3DACTIONGAME_API UTagSystemComponent : public UActorComponentBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void AddTag(const FString& Tag);
	UFUNCTION(BlueprintCallable)
	void RemoveTag(const FString& Tag);
	
protected:
	TMap<FString, TArray<FString>> _TagList;
};
