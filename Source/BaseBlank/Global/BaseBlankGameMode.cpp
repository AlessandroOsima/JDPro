// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBlank.h"
#include "BaseBlankGameMode.h"
#include "Camera/CameraPawn.h"
#include "Character/SpawnPoint/SpawnPoint.h"
#include "EngineUtils.h"

ABaseBlankGameMode::ABaseBlankGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
    // set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/PWN_CAMERA"));
    
    if (PlayerPawnBPClass.Class != NULL)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
}


void ABaseBlankGameMode::HandleMatchIsWaitingToStart()
{
    UWorld* World = GetWorld();

    for (TActorIterator<ASpawnPoint> It(World); It; ++It)
    {
        It->Spawn();
    }
    
    Super::HandleMatchIsWaitingToStart();
}