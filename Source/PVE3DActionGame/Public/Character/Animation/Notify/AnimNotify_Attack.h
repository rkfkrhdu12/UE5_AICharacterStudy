// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_Attack.generated.h"

/**
 * 
 */
UCLASS()
class PVE3DACTIONGAME_API UAnimNotify_Attack : public UAnimNotify
{
	GENERATED_BODY()
public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float radius = 15.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
	float drawTime = 1.f;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
	TEnumAsByte<ETraceTypeQuery> traceType = ETraceTypeQuery::TraceTypeQuery3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
	bool bDrawDebugTrace = true;
};
