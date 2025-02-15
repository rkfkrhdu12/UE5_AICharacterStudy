// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorComponentBase.h"
#include "InputSystemComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterInputRecive, uint8, InputType);

UENUM(BlueprintType)
enum class ECharacterInput : uint8
{
	Attack  UMETA(DisplayName = "Attack"),    // 공격 상태
	Dodge   UMETA(DisplayName = "Dodge"),     // 회피 상태
};

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PVE3DACTIONGAME_API UInputSystemComponent : public UActorComponentBase
{
	GENERATED_BODY()
public:
	// 키가 입력되었음을 알림
	UPROPERTY(BlueprintAssignable)
	FCharacterInputRecive OnInputRecive;
	
private:
	
};
