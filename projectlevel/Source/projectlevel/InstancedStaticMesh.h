// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InstancedStaticMesh.generated.h"

UCLASS()
class PROJECTLEVEL_API AInstancedStaticMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInstancedStaticMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
		class UInstancedStaticMeshComponent* InstMesh;
	UPROPERTY(EditAnywhere)
		int XPibot;
	UPROPERTY(EditAnywhere)
		int YPibot;
	
};
