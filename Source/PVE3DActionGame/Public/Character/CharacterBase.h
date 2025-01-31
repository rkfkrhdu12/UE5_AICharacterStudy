// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Containers/UnrealString.h"

#include "Character/State/StateSystemComponent.h"
#include "Character/Action/ActionSystemComponent.h"
#include "Character/Attribute/AttributeSystemComponent.h"

#include "CharacterBase.generated.h"

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
	bool InitializeSystem();
	
protected: /* System Components */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|System", meta = (AllowPrivateAccess = true))
	TSubclassOf<UStateSystemComponent> StateSystem;

	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|System", meta = (AllowPrivateAccess = true))
	// TSubclassOf<UActionSystemComponent>  _InputSystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|System", meta = (AllowPrivateAccess = true))
	TSubclassOf<UActionSystemComponent> ActionSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default|System", meta = (AllowPrivateAccess = true))
	TSubclassOf<UAttributeSystemComponent> AttributeSystem;

	
/* UE Default Virtual Functions  */	
public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void BeginPlay() override;

public:
	
protected: /*  */
	/* System Components */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug|System", meta = (AllowPrivateAccess = true))
	UStateSystemComponent* _StateSystemComponent = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug|System", meta = (AllowPrivateAccess = true))
	UActionSystemComponent* _ActionSystemComponent = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug|System", meta = (AllowPrivateAccess = true))
	UAttributeSystemComponent* _AttributeSystemComponent = nullptr;

};
