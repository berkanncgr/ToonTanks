// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTank.generated.h"

class USpringArmComponent;
class UCameraComponent;
class APlayerControllerBase;

UCLASS()
class TOONTANKS_API APawnTank : public APawnBase
{
	GENERATED_BODY()
	
private:

	bool bIsPlayerAlive = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UCameraComponent* Camera;

	FVector MoveDirection;
	FQuat RotationDirection;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
		float MoveSpeed = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
		float RotateSpeed = 100.f;

	void CalculateMoveInput(float Value);
	void CalculateRotateInput(float Value);
	void Move();
	void Rotate();

	APlayerController* PlayerControllerRef;


public:

	APawnTank();

	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void HandleDestruction() override;

	bool GetIsPlayerAlive();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
