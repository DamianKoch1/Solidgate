// Fill out your copyright notice in the Description page of Project Settings.


#include "SurveillanceCamCpp.h"

// Sets default values
ASurveillanceCamCpp::ASurveillanceCamCpp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASurveillanceCamCpp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASurveillanceCamCpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASurveillanceCamCpp::GetCamLocRot_Implementation(FVector& location, FRotator& rotation) const
{
	location = GetActorLocation();
	rotation = GetActorRotation();
}

void ASurveillanceCamCpp::GetActorEyesViewPoint(FVector& location, FRotator& rotation) const
{
	GetCamLocRot(location, rotation);
}

