// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "projectlevelGameMode.h"
#include "projectlevelCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "projectlevelCharacter.h"
#include "Engine.h"
AprojectlevelGameMode::AprojectlevelGameMode()
{
	LoadFirstLevel = "NewWorld_1";
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TowerofAngra/Character/MyprojectlevelCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,TEXT("I'm Alive."));
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	
	FLatentActionInfo ActionInfo;
	UGameplayStatics::LoadStreamLevel(this, LoadFirstLevel, true, true, ActionInfo);
}
