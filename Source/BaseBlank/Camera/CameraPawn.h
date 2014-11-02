// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"
#include "CameraPawn.generated.h"

/**
 * 
 */
UCLASS()
class BASEBLANK_API ACameraPawn : public APawn
{
	GENERATED_UCLASS_BODY()
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
    TSubobjectPtr<class UCameraComponent> Camera;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Movement)
    TSubobjectPtr<class UPawnMovementComponent> MovementComponent;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=CoaCllision)
    TSubobjectPtr<class UBoxComponent> BoxCollider;
    
    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(UInputComponent * _inputComponent) override;
    
    void MoveForward(float _value);
    void MoveSide(float _value);
    void MoveUp(float _value);
    
    virtual UPawnMovementComponent * GetMovementComponent() const override;
    virtual void Tick(float _deltaTime);
};
