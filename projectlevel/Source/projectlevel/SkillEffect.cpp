// Fill out your copyright notice in the Description page of Project Settings.

#include "SkillEffect.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ConstructorHelpers.h"
// Sets default values
ASkillEffect::ASkillEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	//Setup collision volume & Attach Root Component
	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Collision->InitSphereRadius(25.0f);
	RootComponent = Collision;

	//Skill Effect
	static ConstructorHelpers::FObjectFinder<UParticleSystem> EffectParticle(TEXT("/Game/StarterContent/Particles/P_Fire"));
	Effect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Effect"));
	Effect->SetTemplate(EffectParticle.Object);
	Effect->SetupAttachment(Collision);

	//Setup Projectile Setting
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(Collision);
	ProjectileMovementComponent->InitialSpeed = 1000.0f;
	ProjectileMovementComponent->MaxSpeed = 3000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = true;
	ProjectileMovementComponent->Bounciness = 0.3f;
	ProjectileMovementComponent->ProjectileGravityScale = 0.0f;


	//ProjectileMovementComponent = RootComponent;
}

// Called when the game starts or when spawned
void ASkillEffect::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASkillEffect::FireInDirection(const FVector & ShootDirection)
{
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
	
}

// Called every frame
void ASkillEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

