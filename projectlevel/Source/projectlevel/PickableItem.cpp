// Fill out your copyright notice in the Description page of Project Settings.

#include "PickableItem.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"
// Sets default values
APickableItem::APickableItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	//Effect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Effect"));
	RootComponent = ItemMesh;
	
}

// Called when the game starts or when spawned
void APickableItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(0, 0, 1));
}

