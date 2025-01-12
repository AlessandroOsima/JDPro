// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBlank.h"
#include "BTTask_SelectMoveTarget.h"
#include "AIController.h"
#include "Character/BaseCharacter.h"
#include "Character/Components/PathPointsComponent.h"

UBTTask_SelectMoveTarget::UBTTask_SelectMoveTarget(const class FObjectInitializer& PCIP) : Super(PCIP)
{
    NodeName = FString("Select Move Target");
    TargetIndex.AddIntFilter(this);
    TargetObject.AddObjectFilter(this, UObject::StaticClass());
    TargetLocation.AddVectorFilter(this);
}

void UBTTask_SelectMoveTarget::InitializeFromAsset(class UBehaviorTree & _asset)
{
    Super::InitializeFromAsset(_asset);
    
    UBlackboardData* BBAsset = GetBlackboardAsset();
    
    TargetLocation.CacheSelectedKey(BBAsset);
    
    TargetObject.CacheSelectedKey(BBAsset);
    
    TargetIndex.CacheSelectedKey(BBAsset);
}

EBTNodeResult::Type UBTTask_SelectMoveTarget::ExecuteTask(class UBehaviorTreeComponent *OwnerComp, uint8 *NodeMemory)
{
    EBTNodeResult::Type result = EBTNodeResult::Type::Failed;
    
    AAIController * aiController = OwnerComp ? Cast<AAIController>(OwnerComp->GetOwner()) : NULL;
    
    if(aiController != nullptr)
    {
        APawn * target = aiController->GetPawn();
        
        ABaseCharacter * castedTarget = Cast<ABaseCharacter>(target);
        
        if(castedTarget != nullptr)
        {
            UPathPointsComponent * pathPointsCmp = Cast<UPathPointsComponent>(castedTarget->GetComponentByClass(UPathPointsComponent::StaticClass()));
            
            auto PathPoints = pathPointsCmp->GetPathPoints();
            
            int32 currentPathIndex = GetCurrentPathIndex(OwnerComp);
            
            if(PathPoints.Num() != 0)
            {
                OwnerComp->GetBlackboardComponent()->SetValueAsObject(TargetObject.GetSelectedKeyID(), PathPoints[currentPathIndex]);
                OwnerComp->GetBlackboardComponent()->SetValueAsVector(TargetLocation.GetSelectedKeyID(), PathPoints[currentPathIndex]->GetActorLocation());
                result = EBTNodeResult::Type::Succeeded;
            }
            else
            {
                UE_LOG(LogTemp, Log, TEXT("The path points array is empty, unable to choose a target"))
            }
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("The possessed pawn is not a BaseCharacter"))
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("No ai controller found"))
    }
    
    return result;
}

int32 UBTTask_SelectMoveTarget::GetCurrentPathIndex(const class UBehaviorTreeComponent * OwnerComp) const
{
    int currentPathIndex = OwnerComp->GetBlackboardComponent()->GetValueAsInt(TargetIndex.GetSelectedKeyID());
    return currentPathIndex;
}

FString UBTTask_SelectMoveTarget::GetStaticDescription() const
{
    bool isTLValid = TargetLocation.SelectedKeyName.IsValid();
    bool isTIValid = TargetLocation.SelectedKeyName.IsValid();
    
    if(!isTLValid || !isTIValid)
    {
        return FString::Printf(NodeName.GetCharArray().GetData());
    }
    else
    {
        //return FString::Printf(NodeName.GetCharArray().GetData());
        return FString::Printf(TEXT("Moving to %s with index %s"), TargetLocation.SelectedKeyName.ToString().GetCharArray().GetData(), TargetIndex.SelectedKeyName.ToString().GetCharArray().GetData());
    }
}