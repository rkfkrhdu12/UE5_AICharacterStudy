// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Animation/Notify/AnimNotify_Attack.h"

#include <Components/ArrowComponent.h>

#include "Kismet/KismetSystemLibrary.h"

void UAnimNotify_Attack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (radius > 0.f)
	{
		if (MeshComp)
		{
			TArray<FHitResult> hitResults;
			TArray<AActor*> ignoreActors;

			FVector sphereLocation = MeshComp->GetSocketLocation("CollisionPoint");

			TArray<UArrowComponent*> arrowComponents;
			if (MeshComp->GetOwner())
			{
				//MeshComp->GetOwner()->GetComponents<UArrowComponent>(arrowComponents);
				for (const UArrowComponent* arrowComp : arrowComponents)
				{
					if (arrowComp)
						if (arrowComp->GetName() == "AttackPoint")
							sphereLocation = arrowComp->GetComponentLocation();
				}
			}

			bool bhit = UKismetSystemLibrary::SphereTraceMulti(MeshComp->GetOwner(), 
				// StartLoca	EndLoca			SphereRad
				sphereLocation, sphereLocation, radius, 
				// TraceType
				traceType,
				
				false, ignoreActors,

				// DrawDebugTraceType
				(bDrawDebugTrace ? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None),
				// HitResults
				hitResults,

				true, FLinearColor::Red, FLinearColor::Green, drawTime);

			if (bhit)
			{
				TArray<AActor*> hitActors;
				for (const FHitResult& hitResult : hitResults)
				{
					if (hitResult.bBlockingHit)
					{
						if (hitResult.GetActor())
						{
							if (!hitActors.Contains(hitResult.GetActor()))
							{
								hitActors.Add(hitResult.GetActor());

								FName HitBoneName = hitResult.BoneName;
								UE_LOG(LogTemp, Log, TEXT("Collision with %s"), *HitBoneName.ToString());
							}
						}
					}
				}
			}
			else
			{
			}
		}
	}
}
