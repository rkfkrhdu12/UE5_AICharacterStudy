// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayStateBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class PVE3DACTIONGAME_API UGameplayStateBase : public UObject
{
	GENERATED_BODY()
public:
	UGameplayStateBase();
	/* Main Functions */
public:
	// 생성될때 * StateSystem에 의해 컨트롤됨.
	void BeginPlay();

	// 다음 상태로 이동 가능한지 * StateSystem에 의해 컨트롤됨.
	bool IsTransition(FName TransStateName) const; 

	// 상태가 시작될때 * StateSystem에 의해 컨트롤됨.
	void OnEnter();

	// 상태가 종료될때 * StateSystem에 의해 컨트롤됨.
	void OnExit();

	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/* Variables */
	

	// State의 이름
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|EditorModify", meta = (AllowPrivateAccess = true))
	FString _Name;
	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/* Get Set Function */
public:

	UFUNCTION(BlueprintCallable)
	const FString& GetStateName() const { return _Name; }


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/* BlueprintModify Function */

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Enter();
	virtual void Enter_Implementation() {}

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Exit();
	virtual void Exit_Implementation() {}
	
};
