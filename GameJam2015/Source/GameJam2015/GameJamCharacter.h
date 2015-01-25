// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "GameJamCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM2015_API AGameJamCharacter : public ACharacter
{
	GENERATED_BODY()
	
public:

	//AGameJamCharacter(const FObjectInitializer& ObjectInitializer);

	void SetHeldObject(AActor* object);

	AActor* GetHeldObject();

	void PickUpObject(AActor* object);

	void DropObject();

	bool CheckForPickup(FHitResult* RV_Hit, FCollisionQueryParams* RV_TraceParams);

	void PickUpAction();

protected:

	class AActor* HeldObject;

	float PlayerInteractionDistance;


	
	
};
