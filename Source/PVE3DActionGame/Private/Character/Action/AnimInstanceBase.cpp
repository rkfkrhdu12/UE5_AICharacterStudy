// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Action/AnimInstanceBase.h"

void UAnimInstanceBase::OnNotifyBroadcast(const FString& Name)
{
	OnAnimationNotify.Broadcast(FName(*Name));
}
