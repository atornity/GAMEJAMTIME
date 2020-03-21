// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnimInstance.h"
#include "PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UPlayerAnimInstance::UPlayerAnimInstance()
{

}

void UPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
		
	//cache pawn
	if (Owner == nullptr)
	{
		Owner = TryGetPawnOwner();
	}
}

void UPlayerAnimInstance::NativeUpdateAnimation(float DeltaTimeX)
{
	Super::NativeUpdateAnimation(DeltaTimeX);

	//cache pawn
	if (Owner == nullptr)
	{
		Owner = TryGetPawnOwner();
	}

	if (Owner)
	{
		FVector Speed = Owner->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f);
		MovementSpeed = LateralSpeed.Size();

		bIsInAir = Owner->GetMovementComponent()->IsFalling();
	}
}
