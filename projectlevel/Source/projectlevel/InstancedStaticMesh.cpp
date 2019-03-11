// Fill out your copyright notice in the Description page of Project Settings.

#include "InstancedStaticMesh.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"
// Sets default values
AInstancedStaticMesh::AInstancedStaticMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	InstMesh = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Instanced Mesh"));
	InstMat = CreateDefaultSubobject<UMaterial>(TEXT("Instanced Material"));
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> IMesh(TEXT("/Game/TowerofAngra/Object/SM_Barrel"));
	
	RootComponent = InstMesh;
	
	
	//InstMesh->SetStaticMesh(IMesh.Object);

	//InstMesh->SetMaterial(0,InstMat);

}

// Called when the game starts or when spawned
void AInstancedStaticMesh::BeginPlay()
{
	Super::BeginPlay();
	InstMesh->RegisterComponent();
	InstMesh->SetFlags(RF_Transactional);
	this->AddInstanceComponent(InstMesh);
	//Set Instance Transform & Location
	for (int x = 0; x < XPibot; x++)
	{
		for (int y = 0; y < YPibot; y++)
		{
			FTransform InstanceTransform;
			FVector SpawnLocation((x-(XPibot/2))*interval, (y-(YPibot/2))*interval, 0.0f);
			InstanceTransform.SetLocation(SpawnLocation);
			InstMesh->SetMaterial(0,InstMat);
			InstMesh->AddInstance(InstanceTransform);
		}
	}
	
}

// Called every frame
void AInstancedStaticMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



