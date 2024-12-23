// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CombatPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PVE3DACTIONGAME_API ACombatPlayerController : public APlayerController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
};
