// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBlank.h"
#include "BTDecorator_DeadState.h"
#include "Character/BaseCharacter.h"
#include "Character/Components/LifeComponent.h"

UBTDecorator_DeadState::UBTDecorator_DeadState(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
    NodeName = "Dead";
}


bool UBTDecorator_DeadState::CanEnterInState(ABaseCharacter * _target) const
{
    ULifeComponent * life = _target->FindComponentByClass<ULifeComponent>();
    
    if(!life)
    {
        UE_LOG(LogTemp, Error, TEXT("[UBTDecorator_NormalState]This actor has no life component"))
        return  false;
    }
    
    bool canEnter = false;
    
    if(life->GetLife() <= 0)
    {
        canEnter = true;
    }
    
    return canEnter;
}