// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponentBase.h"
#include "StateSystemComponent.generated.h"


class UGameplayStateBase;

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PVE3DACTIONGAME_API UStateSystemComponent : public UActorComponentBase
{
	GENERATED_BODY()
public:
	UStateSystemComponent();

	/* Main System */
public:
	void BeginPlayComponent();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
protected: /* Variables */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug", meta = (AllowPrivateAccess = true))
	TArray<UGameplayStateBase*> _States;


	

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/* UE Default Virtual Functions  */
protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
protected: /* SubClass Variables */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default", meta = (AllowPrivateAccess = true))
	TArray<TSubclassOf<UGameplayStateBase>> States;

};
