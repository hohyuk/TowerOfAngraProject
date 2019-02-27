// Fill out your copyright notice in the Description page of Project Settings.

#include "VillageConstructor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ActorComponent.h"
#include "Components/BoxComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine.h"
#include "ConstructorHelpers.h"
#include "Components/InstancedStaticMeshComponent.h"


// Sets default values
AVillageConstructor::AVillageConstructor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set Buildings Array
	OriginBuild = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Original MeshComponent"));
	
	RootComponent = OriginBuild;
	OriginMaterial = CreateDefaultSubobject<UMaterial>(TEXT("Origin Material"));

	OriginBuild->SetMaterial(0, OriginMaterial);
	CollisionVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Volume"));
	CollisionVolume->SetBoxExtent(FVector(100, 100, 100));
	CollisionVolume->SetCollisionProfileName("Trigger");
	CollisionVolume->SetupAttachment(RootComponent);
	CollisionVolume->SetWorldLocation(FVector(200, 200, 100));
	CollisionVolume->OnComponentBeginOverlap.AddUniqueDynamic(this, &AVillageConstructor::OverlapBegins);


}



// Called when the game starts or when spawned
void AVillageConstructor::BeginPlay()
{
	Super::BeginPlay();
	
	//DrawDebugBox(GetWorld(), GetActorLocation(), FVector(100, 100, 100), FColor::Blue, true, -1, 0, 10);
	

}

// Called every frame
void AVillageConstructor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void AVillageConstructor::OverlapBegins(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, int32 OtherbodyIdx, bool bFromSweep, const FHitResult & SweepHit)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComponent != nullptr))	
	{	
		if (Spawn)
		{
			UWorld* world = GetWorld();
			if (world)
			{
				FActorSpawnParameters Sparam;
				Sparam.Owner = this;
				FRotator rotate;
				FVector Location = this->GetActorLocation() + FVector(200, 0, 0);

				world->SpawnActor<AActor>(Spawn, Location, rotate, Sparam);
			}
		}
	}
}

