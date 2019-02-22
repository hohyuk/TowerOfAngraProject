// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VillageConstructor.generated.h"

UCLASS()
class PROJECTLEVEL_API AVillageConstructor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVillageConstructor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* OriginBuild;
	UPROPERTY(EditAnywhere)
		TArray<class UStaticMeshComponent*> Buildings;
	UPROPERTY(EditAnywhere)
		int BuildNum;
	UFUNCTION()	
		void Constructor(int num);


	FActorSpawnParameters Spawninfo;
	FVector SpawnLocation;
	FRotator SpawnRotation;
	FVector SpwanScale;
};
