// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class PVE3DACTIONGAME_API APlayerCharacter : public ACharacter
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
