// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GuardCharacter.generated.h"

UCLASS()
class SOLIDGATE_API AGuardCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGuardCharacter();

	UFUNCTION(BlueprintNativeEvent)
	void GetHeadLocRot(FVector& location, FRotator& rotation) const;
	void GetHeadLocRot_Implementation(FVector& location, FRotator& rotation) const;
	virtual void GetActorEyesViewPoint(FVector& location, FRotator& rotation) const override;
};
