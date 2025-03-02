// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayActionBase.generated.h"


class UActionSystemComponent;
class ACharacterBase;

UCLASS(Blueprintable)
class PVE3DACTIONGAME_API UGameplayActionBase : public UObject
{
	GENERATED_BODY()
public:	
	UGameplayActionBase();

	void OnBeginPlay(ACharacterBase* Character);
	
	void OnEnter();
	void OnExit();
	void OnBreak();

	UFUNCTION()
	virtual void OnReciveStateChange(uint8 State);

protected:
	bool _IsActive = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default", meta = (AllowPrivateAccess = true))
	FName _Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default", meta = (AllowPrivateAccess = true))
	ACharacterBase* _Character;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default", meta = (AllowPrivateAccess = true))
	USkeletalMeshComponent* _Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default", meta = (AllowPrivateAccess = true))
	UAnimInstance* _AnimInstance;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default", meta = (AllowPrivateAccess = true))
	UActionSystemComponent* _ActionSystem;
	
public:
	UFUNCTION(BlueprintCallable)
	const FName& GetActionName() const { return _Name; }
	
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void BeginPlay(ACharacterBase* Character);
	virtual void BeginPlay_Implementation(ACharacterBase* Character) {}
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Enter();
	virtual void Enter_Implementation() {}

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Exit();
	virtual void Exit_Implementation() {}
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Break();
	virtual void Break_Implementation() {}
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ReciveStateChange(uint8 State);
	virtual void ReciveStateChange_Implementation(uint8 State) {}
	
};
