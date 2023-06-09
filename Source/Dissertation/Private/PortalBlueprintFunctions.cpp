// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalBlueprintFunctions.h"

bool UPortalBlueprintFunctions::CompareRotators(FRotator Rotator1, FRotator Rotator2)
{
	if (Rotator1 == Rotator2) { return true; }
	return false;
}