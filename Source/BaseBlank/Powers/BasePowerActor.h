

#pragma once

#include "GameFramework/Actor.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Engine/Texture2D.h"
#include "BasePowerActor.generated.h"


class UPowerConfigurationAsset;

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class BASEBLANK_API ABasePowerActor : public AActor
{
	GENERATED_BODY()
	
    UPROPERTY(EditDefaultsOnly)
    int32 SoulsCost;
    
    UPROPERTY(EditDefaultsOnly)
    FString Name;
    
    UPROPERTY(EditDefaultsOnly)
    FString Description;

    UPROPERTY(EditDefaultsOnly)
    UTexture2D * Icon;
    
    UPROPERTY(EditDefaultsOnly)
    UBehaviorTree * BHTAsset;
   
public:
    virtual bool CanUse()
    {
        return false;
    }
    
    virtual void Use() {}
    
    virtual void StartUse() {}
    
    virtual void EndUse() {}
    
    virtual void Selecting() {}
    
    virtual void UnSelecting() {}
    
};
