// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition,FireRate,true);

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
	
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!PlayerPawn || ReturnDistancetoPlayer() > FireRange) { return; }

	RotateTurret(PlayerPawn->GetActorLocation()); 
	CheckFireCondition();
} 

void APawnTurret::CheckFireCondition()
{
	if (!PlayerPawn || !PlayerPawn->GetIsPlayerAlive()) { return; }

	if (ReturnDistancetoPlayer() <= FireRange)
	{
		Fire(); 
	}
}

float APawnTurret::ReturnDistancetoPlayer()
{
	if (!PlayerPawn) { return 0.f; } // avoid null pointer crashes.

	return FVector::Dist(PlayerPawn->GetActorLocation(),GetActorLocation());
}

void APawnTurret::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}
