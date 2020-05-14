// Fill out your copyright notice in the Description page of Project Settings.


#include "GuardCharacter.h"

// Sets default values
AGuardCharacter::AGuardCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AGuardCharacter::GetHeadLocRot_Implementation(FVector& location, FRotator& rotation) const
{
	location = GetActorLocation() + FVector(0, 0, 50);
	rotation = GetActorRotation();
}


void AGuardCharacter::GetActorEyesViewPoint(FVector& location, FRotator& rotation) const
{
	GetHeadLocRot(location, rotation);
}

