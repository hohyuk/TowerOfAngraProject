// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "AIController.h"
#include "MonsterAIController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTLEVEL_API AMonsterAIController : public AAIController
{
	GENERATED_BODY()
	
	
public:
	AMonsterAIController();
	virtual void Possess(APawn* InPawn) override;
	
	static const FName HomePosKey;
	static const FName PatrolPoskey;
	static const FName TargetKey;

private:
	UPROPERTY()
	class UBehaviorTree* BTAsset;

	UPROPERTY()
	class UBlackboardData* BBAsset;

	
};
