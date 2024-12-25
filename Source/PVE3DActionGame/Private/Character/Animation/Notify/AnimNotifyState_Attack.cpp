// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Animation/Notify/AnimNotifyState_Attack.h"

#include "Kismet/KismetSystemLibrary.h"

#include "Components/ArrowComponent.h"

void UAnimNotifyState_Attack::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{

}

void UAnimNotifyState_Attack::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	accumulatedTime += FrameDeltaTime;

	if (accumulatedTime >= desiredTickRate)
	{
		accumulatedTime = 0.f;

		TArray<FHitResult> hitResults;
		TArray<AActor*> ignoreActors;

		FVector sphereLocation = MeshComp->GetSocketLocation("CollisionPoint");

		TArray<UArrowComponent*> arrowComponents;
		MeshComp->GetOwner()->GetComponents<UArrowComponent>(arrowComponents);
		for (UArrowComponent* arrowComp : arrowComponents)
		{
			if (arrowComp && arrowComp->GetName() == "AttackPoint")
			{
				sphereLocation = arrowComp->GetComponentLocation();
			}
		}

		bool bHit = UKismetSystemLibrary::SphereTraceMulti(MeshComp->GetOwner(), sphereLocation, sphereLocation, radius,
			ETraceTypeQuery::TraceTypeQuery1, true, ignoreActors, EDrawDebugTrace::ForDuration, hitResults, true);
		if (bHit)
		{

		}
	}
}

void UAnimNotifyState_Attack::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
}
