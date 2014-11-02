// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBlank.h"
#include "NPCController.h"
#include "Character/BaseCharacter.h"

NPCControllerBlackBoardKeys ANPCController::BlackboardKeys = NPCControllerBlackBoardKeys();

ANPCController::ANPCController(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
    BHTComponent = PCIP.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorTreeComponent"));
    BlackboardComponent = PCIP.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComponent"));
}

void ANPCController::BeginPlay()
{
    Super::BeginPlay();
    
    ensureMsg(BHTAsset != nullptr,TEXT("[BaseCharacter]No bht asset found"));
    
    BlackboardComponent->InitializeBlackboard(BlackboardAsset);
    
    BHTComponent->StartTree(BHTAsset);
    BHTComponent->PrimaryComponentTick.bCanEverTick = true;
    
    SetupBlackboardKeys();
}

void ANPCController::SetupBlackboardKeys()
{
    //Setup blk keys here
    ABaseCharacter * toPossess = Cast<ABaseCharacter>(GetPawn());
    
    if(toPossess)
    {
        BlackboardComponent->SetValueAsObject(ANPCController::BlackboardKeys.TargetActor, toPossess);
    }
}

void ANPCController::Tick(float _deltaTime)
{
    
    ABaseCharacter * BaseChr = Cast<ABaseCharacter>(BlackboardComponent->GetValueAsObject(ANPCController::BlackboardKeys.TargetActor));
    
    if(BaseChr)
    {
        UE_LOG(LogTemp, Log, TEXT("true"))
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("false"))
    }
    
}

void ANPCController::Possess(APawn *_pawn)
{
    Super::Possess(_pawn);
}