// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryPlaceable.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DISSERTATION_API UInventoryPlaceable : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintGetter=GetLocation, BlueprintSetter=SetLocation)
	FVector location;
	UPROPERTY(EditAnywhere, BlueprintGetter = GetRotation, BlueprintSetter = SetRotation)
	FRotator rotation;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetStoredItem, BlueprintSetter = SetStoredItem)
	AActor* storedItem;

public:	
	// Sets default values for this component's properties
	UInventoryPlaceable();

	#pragma region Getters
	UFUNCTION(BlueprintGetter)
	FVector GetLocation() { return location; }
	UFUNCTION(BlueprintGetter)
	FRotator GetRotation() { return rotation; }
	
	UFUNCTION(BlueprintGetter)
	AActor* GetStoredItem() { return storedItem; }
	#pragma endregion

	#pragma region Setters
	UFUNCTION(BlueprintSetter)
	void SetLocation(FVector targetLocation) { location = targetLocation; }
	UFUNCTION(BlueprintSetter)
	void SetRotation(FRotator targetRotation) { rotation = targetRotation; }
	
	UFUNCTION(BlueprintSetter)
	void SetStoredItem(AActor* targetItem) { storedItem = targetItem; }
	#pragma endregion

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
