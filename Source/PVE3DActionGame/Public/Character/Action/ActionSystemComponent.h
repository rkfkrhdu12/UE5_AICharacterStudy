// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponentBase.h"
#include "ActionSystemComponent.generated.h"


class UGameplayActionBase;

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PVE3DACTIONGAME_API UActionSystemComponent : public UActorComponentBase
{
	GENERATED_BODY()
public:	
	UActionSystemComponent();

public:

	UFUNCTION(BlueprintCallable)
	void StartAction(FName ActionName);
	UFUNCTION(BlueprintCallable)
	void EndAction(FName ActionName);
	UFUNCTION(BlueprintCallable)
	void ForceEndAction(FName ActionName);

	UFUNCTION()
	void OnReciveStateChange(uint8 StateType);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug", meta = (AllowPrivateAccess = true))
	TMap<FName, UGameplayActionBase*> _Actions;
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void BeginPlayComponent() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
protected: /* SubClass Variables */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default", meta = (AllowPrivateAccess = true))
	TArray<TSubclassOf<UGameplayActionBase>> Actions;


public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ReciveStateChange(uint8 StateType);
	void ReciveStateChange_Implementation(uint8 StateType) {}

};
