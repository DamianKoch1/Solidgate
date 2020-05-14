// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionTypes.h"
#include "Runtime/AIModule/Classes/Perception/AISense.h"
#include "Runtime/AIModule/Classes/Perception/AISense_Sight.h"
#include "Runtime/AIModule/Classes/Perception/AISense_Hearing.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionComponent.h"
#include "Runtime/AIModule/Classes/Perception/AISenseConfig_Sight.h"
#include "Runtime/AIModule/Classes/Perception/AISenseConfig_Hearing.h"
#include "AIController.h"
#include "GuardAIController.generated.h"

/**
 * 
 */
UCLASS()
class SOLIDGATE_API AGuardAIController : public AAIController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void Initialize(UAIPerceptionComponent* _perceptionSight, UAIPerceptionComponent* _perceptionHearing);


	UFUNCTION(BlueprintCallable)
	void SetSightRadius(float newRadius);

	UFUNCTION(BlueprintGetter)
	float GetSightRadius();

	UPROPERTY(BlueprintGetter = GetSightRadius)
	float sightRadius;


	UFUNCTION(BlueprintCallable)
	void SetSightAngle(float newAngle);

	UFUNCTION(BlueprintGetter)
	float GetSightAngle();
	
	UPROPERTY(BlueprintGetter = GetSightAngle)
	float sightAngle;


	UFUNCTION(BlueprintCallable)
	void SetHearingRange(float newRange);

	UFUNCTION(BlueprintGetter)
	float GetHearingRange();

	UPROPERTY(BlueprintGetter = GetHearingRange)
	float hearingRange;


	UPROPERTY(BlueprintReadOnly)
	UAISenseConfig_Sight* configSight;

	UPROPERTY(BlueprintReadOnly)
	UAISenseConfig_Hearing* configHearing;

	
	
private:
	UAIPerceptionComponent* perceptionSight;
	UAIPerceptionComponent* perceptionHearing;
	
};
