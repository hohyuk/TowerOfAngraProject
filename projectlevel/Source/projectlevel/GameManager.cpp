// Fill out your copyright notice in the Description page of Project Settings.

#include "GameManager.h"
#include "Monster.h"
#include "Engine/World.h"
#include<vector>
#include<string>
#include<algorithm>

// Sets default values
AGameManager::AGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//this is server's coding area
	if (true)
	{
		return;
	}
}


void AGameManager::SpawnMonster()
{

	UWorld* world = GetWorld();
	////Spawn Actor with Static Class
	//FActorSpawnParameters Sparam;
	FActorSpawnParameters Sparam;
	Sparam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	Sparam.Owner = this;
	Monster = world->SpawnActor<AMonster>(AMonster::StaticClass(), FVector(0, 0, 0), FRotator(0, 0, 0), Sparam);
}

