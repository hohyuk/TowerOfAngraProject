// Fill out your copyright notice in the Description page of Project Settings.

#include "Wall.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AWall::AWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Wall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wall"));
	RootComponent = Wall;

}

// Called when the game starts or when spawned
void AWall::BeginPlay()
{
	Super::BeginPlay();
	//Set Rotation by Enumeration
	if (Dir = EDirection::DIR_FRONT)
	{
		Wall->SetRelativeRotation(FRotator(0,0,0));
	}
	else if (Dir = EDirection::DIR_BACK)
	{
		Wall->SetRelativeRotation(FRotator(0, 90, 0));
	}
	else if (Dir = EDirection::DIR_RIGHT)
	{
		Wall->SetRelativeRotation(FRotator(0, 180, 0));
	}
	else if (Dir = EDirection::DIR_LEFT)
	{
		Wall->SetRelativeRotation(FRotator(0, 270, 0));
	}
}

// Called every frame
void AWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

