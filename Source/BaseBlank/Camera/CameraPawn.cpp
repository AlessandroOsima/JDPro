// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBlank.h"
#include "CameraPawn.h"


ACameraPawn::ACameraPawn(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
    //UE_LOG(LogTemp, Log, TEXT("Spawning camera controller"));
    
    BoxCollider = PCIP.CreateDefaultSubobject<UBoxComponent>(this, TEXT("BoxCollider"));
    BoxCollider->SetBoxExtent(FVector(1,1,1),true);

    MovementComponent = PCIP.CreateDefaultSubobject<UFloatingPawnMovement>(this, TEXT("MovewmentComponent"));
    MovementComponent->UpdatedComponent = BoxCollider;
    
    RootComponent = BoxCollider;
    
    Camera = PCIP.CreateDefaultSubobject<UCameraComponent>(this, FName("CameraComponent"));
    Camera->AttachTo(RootComponent);
    Camera->bUsePawnControlRotation = true;
}


void ACameraPawn::BeginPlay()
{
    Super::BeginPlay();
    MovementComponent->RegisterComponent();
    //UE_LOG(LogTemp, Log, TEXT("Starting game"));
}

void ACameraPawn::SetupPlayerInputComponent(UInputComponent * _inputComponent)
{
    //Ignore default axis mappings
    //Super::SetupPlayerInputComponent(_inputComponent);
    check(InputComponent);
    _inputComponent->BindAxis("MoveForward", this, &ACameraPawn::MoveForward);
    _inputComponent->BindAxis("MoveSide", this, &ACameraPawn::MoveSide);
    _inputComponent->BindAxis("MoveUp", this, &ACameraPawn::MoveUp);
}



void ACameraPawn::MoveForward(float _value)
{
    if(_value != 0)
    {
        //UE_LOG(LogTemp, Log, TEXT("MOVE FORWARD WITH VALUE %f"), _value)
        this->AddMovementInput(FVector(1,0,0),_value);
    }
}

void ACameraPawn::MoveSide(float _value)
{
    if(_value != 0)
    {
        //UE_LOG(LogTemp, Log, TEXT("MOVE SIDEWAYS WITH VALUE %f"), _value)
        this->AddMovementInput(FVector(0,1,0),_value);
    }
}

void ACameraPawn::Tick(float _deltaTime)
{
    if(this->GetController())
    {
        auto controller = this->GetController();
        controller->GetWorld();
    }
}

void ACameraPawn::MoveUp(float _value)
{
    this->AddMovementInput(FVector(0,0,1),_value);
}

UPawnMovementComponent * ACameraPawn::GetMovementComponent() const
{
    return MovementComponent;
}

