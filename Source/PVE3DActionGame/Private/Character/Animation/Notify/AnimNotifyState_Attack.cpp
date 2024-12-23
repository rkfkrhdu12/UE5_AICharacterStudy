// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Animation/Notify/AnimNotifyState_Attack.h"

#include "Kismet/KismetSystemLibrary.h"

#include "Components/ArrowComponent.h"

void UAnimNotifyState_Attack::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{

}

void UAnimNotifyState_Attack::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	AccumulatedTime += FrameDeltaTime;

	if (AccumulatedTime >= DesiredTickRate)
	{
		AccumulatedTime = 0.f;

		TArray<FHitResult> HitResults;
		TArray<AActor*> ignoreActors;

		FVector SphereLocation = MeshComp->GetSocketLocation("CollisionPoint");

		TArray<UArrowComponent*> ArrowComponents;
		MeshComp->GetOwner()->GetComponents<UArrowComponent>(ArrowComponents);
		for (UArrowComponent* ArrowComp : ArrowComponents)
		{
			if (ArrowComp && ArrowComp->GetName() == "AttackPoint")
			{
				SphereLocation = ArrowComp->GetComponentLocation();
			}
		}

		bool bHit = UKismetSystemLibrary::SphereTraceMulti(MeshComp->GetOwner(), SphereLocation, SphereLocation, SphereRadius,
			ETraceTypeQuery::TraceTypeQuery1, true, ignoreActors, EDrawDebugTrace::ForDuration, HitResults, true);
		if (bHit)
		{

		}
	}
}

void UAnimNotifyState_Attack::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
}
