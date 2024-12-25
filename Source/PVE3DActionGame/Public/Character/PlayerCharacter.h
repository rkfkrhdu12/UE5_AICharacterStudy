// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "PlayerCharacter.generated.h"

UENUM(BlueprintType)
enum class EPlayerCharacterStateType : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	Attack UMETA(DisplayName = "Attack"),
	Look UMETA(DisplayName = "Look"),
	Die UMETA(DisplayName = "Die"),
	Dead UMETA(DisplayName = "Dead")
};

UCLASS()
class PVE3DACTIONGAME_API APlayerCharacter : public ACharacterBase
{
	GENERATED_BODY()

public:
	APlayerCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnyWhere, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* _SpringArm;

	UPROPERTY(EditAnyWhere, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* _Camera;


};
