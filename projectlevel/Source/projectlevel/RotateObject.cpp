// Fill out your copyright notice in the Description page of Project Settings.

#include "RotateObject.h"


// Sets default values
ARotateObject::ARotateObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RotateSpeed = 30.f;
}

// Called when the game starts or when spawned
void ARotateObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotateObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0.f, RotateSpeed * DeltaTime, 0.f));
}

