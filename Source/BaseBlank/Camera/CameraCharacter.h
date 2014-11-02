// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "CameraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class BASEBLANK_API ACameraCharacter : public ACharacter
{
	GENERATED_UCLASS_BODY()

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
    TSubobjectPtr<class UCameraComponent> Camera;
    
    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(UInputComponent * _inputComponent) override;
    
    void MoveForward(float _value);
    void MoveSide(float _value);
    void Zoom(float _value);
    virtual void K2_UpdateCustomMovement(float deltaTime);
	
};
