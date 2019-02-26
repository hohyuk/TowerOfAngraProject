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
		class UBoxComponent* CollisionVolume;
	UPROPERTY(EditAnywhere)
		class UMaterial* OriginMaterial;
	UPROPERTY(EditAnywhere)
		class UMaterial* ChangedMaterial;
	UPROPERTY(EditAnywhere)
		int BuildNum;
	UFUNCTION()	
		void Constructor(int num);
	UFUNCTION()
		void OverlapBegins(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherbodyIdx, bool bFromSweep, const FHitResult& SweepHit);
	UPROPERTY()
		int Count;

};
