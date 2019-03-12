// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SkillEffect.generated.h"

UCLASS()
class PROJECTLEVEL_API ASkillEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASkillEffect();
	void FireInDirection(const FVector& ShootDirection);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	class UParticleSystemComponent* Effect;

	UPROPERTY(VisibleDefaultsOnly,Category = projectile)
	class USphereComponent* Collision;
	
	UPROPERTY(VisibleAnywhere, Category = Movement)
	class UProjectileMovementComponent* ProjectileMovementComponent;
};
