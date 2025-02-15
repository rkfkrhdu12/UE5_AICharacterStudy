// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponentBase.h"
#include "StateSystemComponent.generated.h"

class UGameplayStateBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterStateChanged, uint8, StateType);

UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	Idle UMETA(DisplayName = "Idle"), // 대기 상태
	Attack UMETA(DisplayName = "Attack"), // 공격 상태
	Dodge UMETA(DisplayName = "Dodge"), // 회피 상태
	Hit UMETA(DisplayName = "Hit"), // 피격 상태
	Dead UMETA(DisplayName = "Dead"), // 사망 상태
	LAST,
};

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PVE3DACTIONGAME_API UStateSystemComponent : public UActorComponentBase
{
	GENERATED_BODY()

public:
	UStateSystemComponent();

	// ChangeState에서 Broadcast 됨
	// 각 상태 변화를 체크해야 하는 곳에서 Add 됨
	FCharacterStateChanged OnStateChanged;

	/* Main System */
public:
	// BeginPlay 에서 호출됨
	/// TSub로 된 CharacterState들을 실제화 시키고 바인딩
	virtual void BeginPlayComponent() override;

	// 내 외부 입력등을 통해 호출됨
	/// State가 변경 가능한지 체크 후 변경, 이벤트 호출 실패 시 변경하지 않음
	void ChangeState(uint8 StateType);
	UFUNCTION(BlueprintCallable)
	void ChangeState(ECharacterState StateType);
	
protected:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ReciveInputKey(uint8 InputType);
	virtual void ReciveInputKey_Implementation(uint8 InputType);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
protected: /* Variables */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug", meta = (AllowPrivateAccess = true))
	TMap<uint8, UGameplayStateBase*> _States;

	// Super::BeginPlay 전에 세팅 해야함.
	uint8 StateCount = static_cast<uint8>(ECharacterState::LAST);
	
	TMap<uint8, FName> _StateNames;
	TMap<FName, uint8> _NameStates;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default|State", meta = (AllowPrivateAccess = true))
	uint8 _CurrentIndex = static_cast<uint8>(ECharacterState::Idle);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default|State", meta = (AllowPrivateAccess = true))
	uint8 _PrevIndex = static_cast<uint8>(ECharacterState::Idle);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default|State", meta = (AllowPrivateAccess = true))
	uint8 _ChangeIndex = static_cast<uint8>(ECharacterState::LAST);
	
	
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
