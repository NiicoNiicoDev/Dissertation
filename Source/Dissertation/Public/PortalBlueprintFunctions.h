// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PortalBlueprintFunctions.generated.h"

/**
 * 
 */
UCLASS()
class DISSERTATION_API UPortalBlueprintFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Portals")
		static bool CompareRotators(FRotator Rotator1, FRotator Rotator2);
};
