// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Tag/TagSystemComponent.h"

void UTagSystemComponent::AddTag(const FString& Tag)
{
	if (Tag.IsEmpty()) return;

	int32 ChildStartIndex;
	if (!Tag.FindLastChar('.', ChildStartIndex)) return;
	
	FString ParentString = Tag.Left(ChildStartIndex);
	
	if (!_TagList.Contains(ParentString))
		_TagList.Add(ParentString, std::initializer_list<FString>());

	TArray<FString>* CurrentSelectList = &_TagList[ParentString];
	if (!CurrentSelectList) return;
	
	FString ChildString = Tag.Mid(ChildStartIndex + 1, Tag.Len() - (ChildStartIndex + 1)); 
	CurrentSelectList->Add(ChildString);
}

void UTagSystemComponent::RemoveTag(const FString& Tag)
{
	if (Tag.IsEmpty()) return;

	int32 ChildStartIndex;
	if (!Tag.FindLastChar('.', ChildStartIndex)) return;
	
	FString ParentString = Tag.Left(ChildStartIndex);
	
	if (!_TagList.Contains(ParentString)) return;

	TArray<FString>* CurrentSelectList = &_TagList[ParentString];
	if (!CurrentSelectList) return;
	
	FString ChildString = Tag.Mid(ChildStartIndex + 1, Tag.Len() - (ChildStartIndex + 1));
	if (CurrentSelectList->Contains(ChildString))
		CurrentSelectList->Remove(ChildString);
}

bool UTagSystemComponent::IsTag(const FString& Tag) const
{
	if (Tag.IsEmpty()) return false;

	int32 ChildStartIndex;
	if (!Tag.FindLastChar('.', ChildStartIndex)) return false;
	
	FString ParentString = Tag.Left(ChildStartIndex);
	
	if (!_TagList.Contains(ParentString)) return false;

	const TArray<FString>* CurrentSelectList = &_TagList[ParentString];
	if (!CurrentSelectList) return false;
	
	FString ChildString = Tag.Mid(ChildStartIndex + 1, Tag.Len() - (ChildStartIndex + 1));
	return CurrentSelectList->Contains(ChildString);
}
