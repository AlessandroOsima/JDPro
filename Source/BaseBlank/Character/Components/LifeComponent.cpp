// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBlank.h"
#include "LifeComponent.h"
#include "Character/BaseCharacter.h"
#include "Character/Components/LifeComponent.h"
#include "Character/Configuration/CharacterConfigurationAsset.h"

ULifeComponent::ULifeComponent(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
    m_bbKeyObserver = FOnBlackboardChange::CreateUObject(this, &ULifeComponent::OnApplyDamage);
}


float ULifeComponent::GetLife()
{
    return Life;
}

void ULifeComponent::SetLife(float _life)
{
    Life = _life;
    
    if(Life < 0)
    {
        Life = 0;
    }
}

void ULifeComponent::ApplyDamage(float _damage)
{
    Life += _damage;
    
    if(Life < 0)
    {
        Life = 0;
    }
}


void ULifeComponent::BeginPlay()
{
    Super::BeginPlay();
    
    Life = m_ownerConfiguration->Life;
    
    m_ownerBlackboard->RegisterObserver(m_ownerBlackboard->GetKeyID(m_owner->GetBlackboardKeys().DamageInfo) , m_bbKeyObserver);
}

void ULifeComponent::OnApplyDamage(const class UBlackboardComponent *_blk, FBlackboard::FKey _key)
{
    if(_key == m_ownerBlackboard->GetKeyID(m_owner->GetBlackboardKeys().DamageInfo))
    {
        UDamageInfo * damageInfo = Cast<UDamageInfo>(m_ownerBlackboard->GetValueAsObject(m_owner->GetBlackboardKeys().DamageInfo));
        
        if(damageInfo)
        {
            ApplyDamage(damageInfo->DamageAmount);
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("[ULifeComponent]Received wrong blk entry"))
    }
}