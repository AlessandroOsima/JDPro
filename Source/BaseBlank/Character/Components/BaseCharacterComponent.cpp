// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBlank.h"
#include "Character/BaseCharacter.h"
#include "Character/Components/BaseCharacterComponent.h"
#include "Character/Configuration/CharacterConfigurationAsset.h"

UBaseCharacterComponent::UBaseCharacterComponent(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
    this->bAutoActivate = 1;
}


void UBaseCharacterComponent::OnRegister()
{
    Super::OnRegister();
    
    m_owner = Cast<ABaseCharacter>(GetOwner());
    ensureMsg(m_owner != nullptr, TEXT("[BaseCharacterComponent]No owner of type BaseCharacter found"));
}


void UBaseCharacterComponent::BeginPlay()
{
    //UE_LOG(LogTemp, Log, TEXT("BeginPlay of Character Component"))
    m_ownerBlackboard = m_owner->GetBlackboard();
    ensureMsg(m_ownerBlackboard != nullptr, TEXT("[BaseCharacterComponent]No blackboard component found"));
    
    m_ownerConfiguration = m_owner->Configuration;
    ensureMsg(m_ownerBlackboard != nullptr, TEXT("[BaseCharacterComponent]No owner configuration found"));
    
    
    this->OnBeginPlay();
}