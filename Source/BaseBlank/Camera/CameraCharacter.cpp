// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBlank.h"
#include "CameraCharacter.h"


ACameraCharacter::ACameraCharacter(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP)
{
    UE_LOG(LogTemp, Log, TEXT("Spawning camera controller"));
    
    Camera = PCIP.CreateDefaultSubobject<UCameraComponent>(this, FName("CameraComponent"));
    Camera->AttachTo(RootComponent);
    Camera->bUsePawnControlRotation = true;
}


void ACameraCharacter::BeginPlay()
{
    Super::BeginPlay();
    CharacterMovement->MovementMode = EMovementMode::MOVE_Custom;
    CharacterMovement->BrakingDecelerationFlying = CharacterMovement->MaxAcceleration;
    UE_LOG(LogTemp, Log, TEXT("Starting game"));
}

void ACameraCharacter::SetupPlayerInputComponent(UInputComponent * _inputComponent)
{
    //Ignore default axis mappings
    //Super::SetupPlayerInputComponent(_inputComponent);
    check(InputComponent);
    _inputComponent->BindAxis("MoveForward", this, &ACameraCharacter::MoveForward);
    _inputComponent->BindAxis("MoveSide", this, &ACameraCharacter::MoveSide);
    _inputComponent->BindAxis("Zoom", this, &ACameraCharacter::Zoom);
}

void ACameraCharacter::MoveForward(float _value)
{
    if(_value != 0)
    {
        UE_LOG(LogTemp, Log, TEXT("MOVE FORWARD WITH VALUE %f"), _value)
        
        FRotator Rotation = GetControlRotation();
        FVector direction =  FVector(1, 0, 0);   //FRotationMatrix(Rotation).GetUnitAxis(EAxis::X);
        AddMovementInput(direction,_value);
    }
}

void ACameraCharacter::MoveSide(float _value)
{
    if(_value != 0)
    {
        UE_LOG(LogTemp, Log, TEXT("MOVE SIDEWAYS WITH VALUE %f"), _value)
        
        FRotator Rotation = GetControlRotation();
        FVector direction = FRotationMatrix(Rotation).GetUnitAxis(EAxis::Y);
        AddMovementInput(direction,_value);
    }
}

void ACameraCharacter::Zoom(float _value)
{
    if(_value != 0)
    {
        AddMovementInput(FVector(0, 0, 1),_value);
    }
}

void ACameraCharacter::K2_UpdateCustomMovement(float deltaTime)
{
    UE_LOG(LogTemp, Log, TEXT("MOVING x: %f y: %f z: %f" ),CharacterMovement->Velocity.X,CharacterMovement->Velocity.Y,CharacterMovement->Velocity.Z)
    FHitResult Hit(1.f);
    CharacterMovement->SafeMoveUpdatedComponent(CharacterMovement->Velocity,this->GetActorRotation(),true,Hit);
    
    
}

