// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PickupObject.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM2015_API APickupObject : public AActor
{
	GENERATED_BODY()

	APickupObject(const FObjectInitializer& ObjectInitializer);
	
public:

	void SetGravity(bool isGravity);

protected:

	class UStaticMesh* StaticMesh;
	
	
};
