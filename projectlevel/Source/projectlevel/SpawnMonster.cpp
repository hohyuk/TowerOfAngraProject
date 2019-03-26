// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnMonster.h"
#include "Engine.h"
#include "Monster.h"
// Sets default values
ASpawnMonster::ASpawnMonster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 10.f;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;


}

// Called when the game starts or when spawned
void ASpawnMonster::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ASpawnMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, TEXT("Spawn Monster"));
	UWorld* world = GetWorld();
	////Spawn Actor with Static Class
	FActorSpawnParameters Sparam;
	Sparam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	Sparam.Owner = this;
	//static ConstructorHelpers::FObjectFinder<AMonster> Monster(TEXT("/Game/Monster2"));

	world->SpawnActor<AMonster>(AMonster::StaticClass(), this->GetActorLocation(), FRotator(0, 0, 0), Sparam);
}

