// Fill out your copyright notice in the Description page of Project Settings.

#include "VillageConstructor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AVillageConstructor::AVillageConstructor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	OriginBuild = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Origin Mesh Data"));
	OriginBuild->SetupAttachment(RootComponent);
	Constructor(BuildNum);
}

// Called when the game starts or when spawned
void AVillageConstructor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVillageConstructor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVillageConstructor::Constructor(int num)
{
	for (int i = 0; i < num; i++)
	{
		FVector Location(FMath::FRandRange(-1000,1000), FMath::FRandRange(-1000, 1000),0);
		FRotator Rotation(0, FMath::FRandRange(-360, 360), FMath::FRandRange(-10, 10));
		OriginBuild->SetWorldLocationAndRotation(Location, Rotation, false, nullptr, ETeleportType::None);
		BuildingMeshs.Add(OriginBuild);
		
	}
}

