// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Containers/UnrealString.h"

#include "CharacterBase.generated.h"

enum class ECharacterInput : uint8;

UCLASS()
class PVE3DACTIONGAME_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()
public:
	ACharacterBase();

/* Main System */
public:
	// BeginPlay() 에서 호출됨.
	/// TSub형태의 시스템 클래스들을 실제 형태로 Init
	bool RegisterComponents();

	bool StartComponents();

	// 입력이 들어올시 호출됨.
	// Player : 키 입력시
	// NonPlayer : AI에 의한 입력
	UFUNCTION(BlueprintCallable)
	void OnInputKey(ECharacterInput InputType);
	
protected: /* System Components */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|System", meta = (AllowPrivateAccess = true))
	TSubclassOf<class UStateSystemComponent> StateSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|System", meta = (AllowPrivateAccess = true))
	TSubclassOf<class UInputSystemComponent>  InputSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|System", meta = (AllowPrivateAccess = true))
	TSubclassOf<class UActionSystemComponent> ActionSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|System", meta = (AllowPrivateAccess = true))
	TSubclassOf<class UAttributeSystemComponent> AttributeSystem;

/* UE Default Virtual Functions  */	
public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void BeginPlay() override;

protected: /* Activate Variables */
	/* System Components */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug|System", meta = (AllowPrivateAccess = true))
	class UStateSystemComponent* _StateSystemComponent = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug|System", meta = (AllowPrivateAccess = true))
	class UInputSystemComponent* _InputSystemComponent = nullptr;

public:
	class UStateSystemComponent* GetStateComponent() const
	{
		return _StateSystemComponent;
	}

	class UInputSystemComponent* GetInputComponent() const
	{
		return _InputSystemComponent;
	}

	class UActionSystemComponent* GetActionComponent() const
	{
		return _ActionSystemComponent;
	}

	class UAttributeSystemComponent* GetAttributeComponent() const
	{
		return _AttributeSystemComponent;
	}

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug|System", meta = (AllowPrivateAccess = true))
	class UActionSystemComponent* _ActionSystemComponent = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug|System", meta = (AllowPrivateAccess = true))
	class UAttributeSystemComponent* _AttributeSystemComponent = nullptr;

};
