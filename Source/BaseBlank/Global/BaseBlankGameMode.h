// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "BaseBlankGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BASEBLANK_API ABaseBlankGameMode : public AGameMode
{
	GENERATED_UCLASS_BODY()

    virtual void HandleMatchIsWaitingToStart() override;
	
};
