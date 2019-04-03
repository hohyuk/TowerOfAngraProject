// Fill out your copyright notice in the Description page of Project Settings.

#include "Monster.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/WidgetComponent.h"
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

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MonsterMesh(TEXT("/Game/Mannequin/Character/Mesh/SK_Mannequin"));
	GetMesh()->SetSkeletalMesh(MonsterMesh.Object);
	GetMesh()->SetWorldLocation(FVector(0, 0, -100.f), false, NULL, ETeleportType::None);
	GetMesh()->SetWorldRotation(FRotator(0, -90, 0), false, NULL, ETeleportType::None);

	// UI
	HPBarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HPBARWIDGET"));
	HPBarWidget->SetupAttachment(GetMesh());

	HPBarWidget->SetRelativeLocation(FVector(0.f, 0.f, 180.f));
	HPBarWidget->SetWidgetSpace(EWidgetSpace::Screen);
	static ConstructorHelpers::FClassFinder<UUserWidget> UI_HUD(TEXT("/Game/TowerofAngra/UI/UI_HPBar.UI_HPBar_C"));
	if (UI_HUD.Succeeded())
	{
		HPBarWidget->SetWidgetClass(UI_HUD.Class);
		HPBarWidget->SetDrawSize(FVector2D(150.f, 50.f));
	}
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
	
}

// Called to bind functionality to input
void AMonster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

