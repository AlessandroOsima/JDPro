// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataAsset.h"
#include "CharacterConfigurationAsset.generated.h"

/**
 * Contains the character configuration data. These are readonly from code.
 * DO NOT BE FUCKING DUMB AND CHANGE THEM FROM SCRIPTS
 */
UCLASS()
class BASEBLANK_API UCharacterConfigurationAsset : public UDataAsset
{
	GENERATED_UCLASS_BODY()
    
public:
    
	UPROPERTY(EditAnywhere, Category=Life)
    float Life = 0;

    
};
