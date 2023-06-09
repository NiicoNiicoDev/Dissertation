// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

bool UMyBlueprintFunctionLibrary::DoesActorContainClass(AActor* Actor, UClass* ClassToCheck)
{
	if (Actor != nullptr && ClassToCheck != nullptr) 
	{
		if (IsValid(Actor->GetComponentByClass(ClassToCheck))) { return true; }
	}
	
	return false;
}