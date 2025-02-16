// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Tag/TagSystemComponent.h"

void UTagSystemComponent::AddTag(const FString& Tag)
{
	if (Tag.IsEmpty()) return;

	int32 ChildStartIndex;
	if (!Tag.FindLastChar('.', ChildStartIndex)) return;

	FString ParentString = Tag.Left(ChildStartIndex);

	UE_LOG(LogTemp, Log, TEXT("TagSystem AddTag %s %d %s"), *Tag, ChildStartIndex, *ParentString);

}

void UTagSystemComponent::RemoveTag(const FString& Tag)
{
}
