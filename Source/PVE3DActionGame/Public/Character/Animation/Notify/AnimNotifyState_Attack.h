// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "AnimNotifyState_Attack.generated.h"

/**
 * 
 */
UCLASS()
class PVE3DACTIONGAME_API UAnimNotifyState_Attack : public UAnimNotifyState
{
	GENERATED_BODY()
	
public:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration);
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime);
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation);


private:
	float AccumulatedTime = 0.f;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tick")
	float DesiredTickRate = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tick")
	float SphereRadius = 5.f;
};
