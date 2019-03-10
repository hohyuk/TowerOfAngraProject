// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Wall.generated.h"

UCLASS()
class PROJECTLEVEL_API AWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Category = Direction)
		EDirection Dir;
	UPROPERTY(Category = WallType)
		UStaticMeshComponent* Wall;
};
//Set Wall Direction by enumeration
enum class EDirection : uint8
{
	DIR_RIGHT	UMETA(DisplayName = "Right"),
	DIR_LEFT	UMETA(DisplayName = "Left"),
	DIR_FRONT	UMETA(DisplayName = "FRONT"),
	DIR_BACK	UMETA(DisplayName = "BACK"),
};