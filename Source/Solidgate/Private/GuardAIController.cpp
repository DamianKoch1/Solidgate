// Fill out your copyright notice in the Description page of Project Settings.


#include "GuardAIController.h"



void AGuardAIController::Initialize(UAIPerceptionComponent* _perceptionSight, UAIPerceptionComponent* _perceptionHearing)
{
	FAISenseID IdSight = UAISense::GetSenseID(UAISense_Sight::StaticClass());

	if (!IdSight.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Wrong Sight Sense ID"));
		return;
	}

	perceptionSight = _perceptionSight;
	auto config = perceptionSight->GetSenseConfig(IdSight);
	if (config == nullptr) return;
	configSight = Cast<UAISenseConfig_Sight>(config);
	

	FAISenseID IdHearing = UAISense::GetSenseID(UAISense_Hearing::StaticClass());

	if (!IdHearing.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Wrong Hearing Sense ID"));
		return;
	}

	perceptionHearing = _perceptionHearing;
	auto config1 = perceptionHearing->GetSenseConfig(IdHearing);
	if (config1 == nullptr) return;
	configHearing = Cast<UAISenseConfig_Hearing>(config1);


}


void AGuardAIController::SetSightRadius(float newRadius)
{
	float loseSightRange = configSight->LoseSightRadius - configSight->SightRadius;
	configSight->SightRadius = newRadius;
	configSight->LoseSightRadius = configSight->SightRadius + loseSightRange;
	perceptionSight->RequestStimuliListenerUpdate();
}

void AGuardAIController::SetSightAngle(float newAngle)
{
	configSight->PeripheralVisionAngleDegrees = newAngle;
}

float AGuardAIController::GetSightRadius()
{
	return configSight->SightRadius;
}

float AGuardAIController::GetSightAngle()
{
	return configSight->PeripheralVisionAngleDegrees;
}


void AGuardAIController::SetHearingRange(float newRange)
{
	configHearing->HearingRange = newRange;

	perceptionHearing->RequestStimuliListenerUpdate();
}

float AGuardAIController::GetHearingRange()
{
	return configHearing->HearingRange;
}