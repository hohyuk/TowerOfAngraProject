// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "projectlevelCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "ConstructorHelpers.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine.h"
#include "VillageConstructor.h"
//////////////////////////////////////////////////////////////////////////
// AprojectlevelCharacter

AprojectlevelCharacter::AprojectlevelCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	//Create a New Skeletal Mesh
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> CharacterMesh(TEXT("/Game/Mannequin/Character/Mesh/SK_Mannequin"));
	GetMesh()->SetSkeletalMesh(CharacterMesh.Object);
	GetMesh()->SetWorldLocation(FVector(0, 0, -95.f), false, NULL, ETeleportType::None);


	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void AprojectlevelCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	//Custom Action Key
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AprojectlevelCharacter::Attack);
	PlayerInputComponent->BindAction("Skill", IE_Pressed, this, &AprojectlevelCharacter::Skill);
	PlayerInputComponent->BindAction("ToggleSkill", IE_Pressed, this, &AprojectlevelCharacter::ToggleSkill);
	
	PlayerInputComponent->BindAxis("MoveForward", this, &AprojectlevelCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AprojectlevelCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AprojectlevelCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AprojectlevelCharacter::LookUpAtRate);

}

void AprojectlevelCharacter::ToggleSkill()
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

			world->SpawnActor<AVillageConstructor>(Spawn, Location, rotate, Sparam);
		}
	}
}

void AprojectlevelCharacter::Attack()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, TEXT("Attack Enemy."));
}

void AprojectlevelCharacter::Skill()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Blue, TEXT("Using Skill."));
}



void AprojectlevelCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AprojectlevelCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AprojectlevelCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AprojectlevelCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
