// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseBlank.h"
#include "Character/Components/BaseCharacterComponent.h"
#include "Character/BaseCharacter.h"
#include "Character/Configuration/CharacterConfigurationAsset.h"

BaseCharacterBlackBoardKeys ABaseCharacter::s_blackboardKeys = BaseCharacterBlackBoardKeys();

ABaseCharacter::ABaseCharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
    BHTComponent = PCIP.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorTreeComponent"));
    BlackboardComponent = PCIP.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComponent"));
    this->PrimaryActorTick.bCanEverTick = true;
    this->PrimaryActorTick.bStartWithTickEnabled = true;
}


void ABaseCharacter::BeginPlay()
{
    Super::BeginPlay();
    
     ensureMsg(Configuration != nullptr, TEXT("[BaseCharacter]No valid configuration found"));
    
    if(Configuration != nullptr)
    {
        BlackboardAsset = Configuration->BlackboardAsset;
        BHTAsset = Configuration->BehaviorTreeAsset;
    }
    
    SpawnDefaultController();
    
    ensureMsg(BHTAsset != nullptr,TEXT("[BaseCharacter]No bht asset found"));
    
    /*
     HOWTO : Make a BHT/Blackboard couple work
     1-Register and init a blackboard from  it's asset
     2-Register and init a BHT and set it to tick with PrimaryComponentTick.bCanEverTick = true
    */
    
    BlackboardComponent->RegisterComponent();
    BlackboardComponent->InitializeBlackboard(BlackboardAsset);
    
    BHTComponent->RegisterComponent();
    BHTComponent->StartTree(BHTAsset);
    BHTComponent->PrimaryComponentTick.bCanEverTick = true;
    
    auto componentsArray = GetComponentsByClass(UBaseCharacterComponent::StaticClass());
    
    for(UActorComponent * component : componentsArray)
    {
        Cast<UBaseCharacterComponent>(component)->BeginPlay();
    }
}

UBlackboardComponent * ABaseCharacter::GetBlackboard() const
{
    return BlackboardComponent;
}

BaseCharacterBlackBoardKeys ABaseCharacter::GetBlackboardKeys() const
{
    return ABaseCharacter::s_blackboardKeys;
}

void ABaseCharacter::ApplyDamage(UDamageInfo * _damageInfo)
{
    CurrentDamageInfo  = _damageInfo;
    BlackboardComponent->SetValueAsObject(s_blackboardKeys.DamageInfo, _damageInfo);
}

/*
void ABaseCharacter::Tick(float _deltaTime)
{

}
*/