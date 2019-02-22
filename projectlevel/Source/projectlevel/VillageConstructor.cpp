 // Fill out your copyright notice in the Description page of Project Settings.

#include "VillageConstructor.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"
#include "Engine.h"

// Sets default values
AVillageConstructor::AVillageConstructor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	OriginBuild = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Origin Mesh Data"));
	OriginBuild->SetupAttachment(RootComponent);
	//Set Buildings Array

}
	


// Called when the game starts or when spawned
void AVillageConstructor::BeginPlay()
{
	Super::BeginPlay();
	UStaticMeshComponent* Temp;
	Temp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Copyed_Data"));
	Buildings.Init(Temp, BuildNum);
	GetWorld()->SpawnActor<AVillageConstructor>(SpawnLocation,SpawnRotation,Spawninfo);
}

// Called every frame
void AVillageConstructor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVillageConstructor::Constructor(int num)
{

}

