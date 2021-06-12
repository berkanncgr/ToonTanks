// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameModeBase.generated.h"

class APawnTurret;
class APawnTank;
class APlayerControllerBase;

UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
private:
	
	APlayerControllerBase* PlayerControllerRef;
	void HandleGameStart();
	void HandleGameOver(bool PlayerWon);

	APawnTank* PlayerTank;
	int32 TargetTurrets;
	int32 GetTargetTurretCount();


protected:

	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();
	
	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerWon);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Loop", meta = (AllowPrivateAccess = "true"))
	int32 StartDelay=3;

public:

	void ActorDied(AActor* DeadActor);
};
