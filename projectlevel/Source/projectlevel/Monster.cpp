// Fill out your copyright notice in the Description page of Project Settings.

#include "Monster.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "ConstructorHelpers.h"
#include "projectlevelCharacter.h"
#include "Engine.h"
// Sets default values
AMonster::AMonster()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Set Monster's Collision Bound by Capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 100.0f);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MonsterMesh(TEXT("/Game/TowerofAngra/Character/Mannequin/Mesh/SK_Mannequin"));
	GetMesh()->SetSkeletalMesh(MonsterMesh.Object);
	GetMesh()->SetWorldLocation(FVector(0, 0, -100.f), false, NULL, ETeleportType::None);
	GetMesh()->SetWorldRotation(FRotator(0, -90, 0), false, NULL, ETeleportType::None);
}

// Called when the game starts or when spawned
void AMonster::BeginPlay()
{
	Super::BeginPlay();
	Target = Cast<AprojectlevelCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
}

// Called every frame
void AMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Dir = Target->GetActorLocation()- GetActorLocation();

	
	//ctorNormalize(Dir);
	AddActorWorldOffset(Dir);
}

// Called to bind functionality to input
void AMonster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

