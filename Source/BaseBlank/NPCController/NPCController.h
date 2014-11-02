// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NPCController.generated.h"

/**
 * 
 */

struct NPCControllerBlackBoardKeys
{
    const FName TargetActor = FName("PossessedPawn");
};

UCLASS()
class BASEBLANK_API ANPCController : public AAIController
{
    GENERATED_UCLASS_BODY()
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Logic)
    TSubobjectPtr<UBehaviorTreeComponent> BHTComponent;
    
    UPROPERTY(EditDefaultsOnly, Category=Logic)
    UBehaviorTree * BHTAsset;
    
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Logic)
    TSubobjectPtr<UBlackboardComponent> BlackboardComponent;
    
    
    UPROPERTY(EditDefaultsOnly, Category=Logic)
    UBlackboardData * BlackboardAsset;
    
    
    static NPCControllerBlackBoardKeys BlackboardKeys;
    
    virtual void BeginPlay() override;
    virtual void Tick(float _deltaTime) override;
    virtual void Possess(APawn* _pawn) override;
    void SetupBlackboardKeys();
    
public:
    
    NPCControllerBlackBoardKeys GetBlackboardKeys() const
    {
        return ANPCController::BlackboardKeys;
    }
    
};
