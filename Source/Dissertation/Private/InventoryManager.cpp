// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryManager.h"

// Sets default values for this component's properties
UInventoryManager::UInventoryManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	if (this->GetOwner() != nullptr)
		inventoryBounds = (UBoxComponent*)this->GetOwner()->GetComponentByClass(UBoxComponent::StaticClass());
	// ...
}


// Called when the game starts
void UInventoryManager::BeginPlay()
{
	Super::BeginPlay();
	
	FTimerHandle TimerHandle;
	
	GetOwner()->GetWorldTimerManager().SetTimer(TimerHandle, this, &UInventoryManager::GetInventoryOverlappingActors, 0.05f, false);


	// ...
	
}


// Called every frame
void UInventoryManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
}

void UInventoryManager::GetInventoryOverlappingActors() 
{
	TArray<AActor*> overlappingActors;
	inventoryBounds->GetOverlappingActors(overlappingActors, AActor::StaticClass());

	UE_LOG(LogTemp, Warning, TEXT("The integer value is: %d"), overlappingActors.Num());

	for (AActor* actor : overlappingActors)
	{
		if (actor->GetComponentByClass(UInventoryPlaceable::StaticClass()))
		{
			UInventoryPlaceable* inventoryPlaceable = Cast<UInventoryPlaceable>(actor->GetComponentByClass(UInventoryPlaceable::StaticClass()));
			inventoryPlaceables.Add(FInventoryPlaceableActor(inventoryPlaceable->GetOwner()->GetActorLabel(), inventoryPlaceable));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Added Actor to Inventory Placeables Array"));
		}
	}
}

void UInventoryManager::UpdateInventoryContents() 
{
	for (FInventoryPlaceableActor inventoryPlaceable : inventoryPlaceables)
	{
		if (inventoryPlaceable.containerPlaceable->GetStoredItem() == nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("1"));

			return;
		}
		else if (inventoryContents.Num() == 0)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No items in inventory"));

			inventoryContents.Add(FInventoryItemData(inventoryPlaceable.containerPlaceable->GetStoredItem(), inventoryPlaceable.containerPlaceable->GetOwner()));
		}
		else
		{
			for (size_t i = 0; i < inventoryContents.Num(); i++)
			{
				if (inventoryPlaceable.containerPlaceable->GetStoredItem() == inventoryContents[i].itemActor)
				{
					continue;
				}
				else
				{
					inventoryContents.Add(FInventoryItemData(inventoryPlaceable.containerPlaceable->GetStoredItem(), inventoryPlaceable.containerPlaceable->GetOwner()));

					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Item doesn't exist in inventory, adding to inventory"));

					return;
				}
			}
		}
	}
}

void UInventoryManager::UpdateInventoryData()
{
	GetInventoryOverlappingActors();
	UpdateInventoryContents();
}

