// Fill out your copyright notice in the Description page of Project Settings.

#include "Monster.h"
#include "Components/SkeletalMeshComponent.h"
#include "ConstructorHelpers.h"

// Sets default values
AMonster::AMonster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set Mesh
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> Mesh(TEXT("/Game/TowerofAngra/Character/Rinda/Rinda2"));
	MonsterMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	MonsterMesh->SetSkeletalMesh(Mesh.Object);
	//Attach To Root
	MonsterMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);

}

// Called when the game starts or when spawned
void AMonster::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalOffset(FVector(1, 0, 0));
}

