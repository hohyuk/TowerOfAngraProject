// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "projectlevelGameMode.h"
#include "projectlevelCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine.h"
AprojectlevelGameMode::AprojectlevelGameMode()
{
	LoadFirstLevel = "NewWorld_1";
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	FLatentActionInfo ActionInfo;
	UGameplayStatics::LoadStreamLevel(this, LoadFirstLevel, true, true, ActionInfo);
}
