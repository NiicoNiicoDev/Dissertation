// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "InventoryPlaceable.h"
#include "Engine.h"
#include <vector>
#include "InventoryManager.generated.h"


USTRUCT(BlueprintType)
struct FInventoryItemData
{	
	GENERATED_BODY()
		
public:
	UPROPERTY(EditAnywhere)
		AActor* itemActor;

	UPROPERTY(EditAnywhere)
		AActor* itemContainerActor;

	FInventoryItemData() 
	{
		itemActor = nullptr;
		itemContainerActor = nullptr;
	}

	FInventoryItemData(AActor* item, AActor* container)
	{
		itemActor = item;
		itemContainerActor = container;
	}
};

USTRUCT(BlueprintType)
struct FInventoryPlaceableActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		FString actorName;

	UPROPERTY(EditAnywhere)
		UInventoryPlaceable* containerPlaceable;

	FInventoryPlaceableActor()
	{
		actorName = FString("");
		containerPlaceable = nullptr;
	}

	FInventoryPlaceableActor(FString name, UInventoryPlaceable* placeable)
	{
		actorName = name;
		containerPlaceable = placeable;
	}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )

class DISSERTATION_API UInventoryManager : public UActorComponent
{
	GENERATED_BODY()

private:
	
	UPROPERTY(VisibleAnywhere)
	TArray<FInventoryPlaceableActor> inventoryPlaceables;

	UPROPERTY(VisibleAnywhere)
	TArray<FInventoryItemData> inventoryContents;
	
	UPROPERTY(EditAnywhere)
	UBoxComponent* inventoryBounds;

public:	
	// Sets default values for this component's properties
	UInventoryManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void GetInventoryOverlappingActors();

	void UpdateInventoryContents();

	UFUNCTION(BlueprintCallable)
		void UpdateInventoryData();

		
};
