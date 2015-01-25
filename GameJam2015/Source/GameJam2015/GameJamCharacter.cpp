// Fill out your copyright notice in the Description page of Project Settings.

#include "GameJam2015.h"
#include "GameJamCharacter.h"

//AGameJamCharacter::AGameJamCharacter(const FObjectInitializer& ObjectInitializer)
//:Super(ObjectInitializer)
//{
	//HeldObject = NULL;
//}

void AGameJamCharacter::PickUpAction()
{
	//if (HeldObject != NULL)
	//call drop object
	//then return

	FHitResult RV_Hit(ForceInit);
	FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);

	if (CheckForPickup(&RV_Hit, &RV_TraceParams))
	{
		PickUpObject(RV_Hit.GetActor());
	}
}

void AGameJamCharacter::PickUpObject(AActor* object)
{
	SetHeldObject(object);

	//HeldObject->GetGameInstance  
}

bool AGameJamCharacter::CheckForPickup(FHitResult* RV_Hit, FCollisionQueryParams* RV_TraceParams)
{
	FVector CameraLoc;
	FRotator CameraRot;
	GetActorEyesViewPoint(CameraLoc, CameraRot);

	FVector Start = CameraLoc;

	FVector End = CameraLoc + (CameraRot.Vector() * PlayerInteractionDistance);

	RV_TraceParams->bTraceComplex = true;
	RV_TraceParams->bTraceAsyncScene = true;
	RV_TraceParams->bReturnPhysicalMaterial = true;

	//  do the line trace
	bool DidTrace = GetWorld()->LineTraceSingle(
		*RV_Hit,        //result
		Start,        //start
		End,        //end
		ECC_Pawn,    //collision channel
		*RV_TraceParams
		);

	return DidTrace;
}

void AGameJamCharacter::SetHeldObject(AActor* object)
{
	HeldObject = object;
}

AActor* AGameJamCharacter::GetHeldObject()
{
	return HeldObject;
}




