// Fill out your copyright notice in the Description page of Project Settings.

#include "NormalMonster.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "ConstructorHelpers.h"
// Sets default values
ANormalMonster::ANormalMonster()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 100.0f);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MonsterMesh(TEXT("/Game/Mannequin/Character/Mesh/SK_Mannequin"));
	GetMesh()->SetSkeletalMesh(MonsterMesh.Object);
	GetMesh()->SetWorldLocation(FVector(0, 0, -100.f), false, NULL, ETeleportType::None);
	GetMesh()->SetWorldRotation(FRotator(0, -90, 0), false, NULL, ETeleportType::None);

}

// Called when the game starts or when spawned
void ANormalMonster::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANormalMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANormalMonster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

