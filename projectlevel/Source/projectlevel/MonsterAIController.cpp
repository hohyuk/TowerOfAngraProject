// Fill out your copyright notice in the Description page of Project Settings.

#include "MonsterAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

const FName AMonsterAIController::HomePosKey(TEXT("HomePos"));
const FName AMonsterAIController::PatrolPoskey(TEXT("PatrolPos"));
const FName AMonsterAIController::TargetKey(TEXT("Target"));

AMonsterAIController::AMonsterAIController()
{
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT("/Game/TowerofAngra/AI/MonsterBlackboard.MonsterBlackboard"));
	if (BBObject.Succeeded())
	{
		BBAsset = BBObject.Object;
	}

	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("/Game/TowerofAngra/AI/MonsterBehaviorTree.MonsterBehaviorTree"));
	if (BTObject.Succeeded())
	{
		BTAsset = BTObject.Object;
	}
}

void AMonsterAIController::Possess(APawn * InPawn)
{
	Super::Possess(InPawn);

	if (UseBlackboard(BBAsset, Blackboard))
	{
		Blackboard->SetValueAsVector(HomePosKey, InPawn->GetActorLocation());
	}
}
