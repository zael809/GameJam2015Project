// Fill out your copyright notice in the Description page of Project Settings.

#include "GameJam2015.h"
#include "PickupObject.h"

APickupObject::APickupObject(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	TArray<UStaticMeshComponent*> Components;
	GetComponents<UStaticMeshComponent>(Components);
	for (int32 i = 0; i<Components.Num(); i++)
	{
		UStaticMeshComponent* StaticMeshComponent = Components[i];
		StaticMesh = StaticMeshComponent->StaticMesh;
	}
}

void APickupObject::SetGravity(bool isGravity)
{
	//Cast<UPrimitiveComponent, UStaticMeshComponent>(StaticMesh);
}


