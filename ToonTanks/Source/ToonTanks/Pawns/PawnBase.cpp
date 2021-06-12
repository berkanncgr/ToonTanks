// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include "Components/CapsuleComponent.h"
#include "ToonTanks/Actors/ProjectileBase.h"
#include "ToonTanks/Components/HealthComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraShake.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);

	//HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	
}

void APawnBase::RotateTurret(FVector LookAtTarget)
{
	
	//FVector LookAtTargetCleaned = FVector(LookAtTarget.X, LookAtTarget.Y, TurretMesh->GetComponentLocation().Z);
	//FVector StartLocation = TurretMesh->GetComponentLocation();
	
	//FRotator TurretRotation = (FVector(LookAtTarget.X, LookAtTarget.Y, TurretMesh->GetComponentLocation().Z)-TurretMesh->GetComponentLocation()).Rotation();
	//TurretMesh->SetWorldRotation(TurretRotation);

	TurretMesh->SetWorldRotation((FVector(LookAtTarget.X, LookAtTarget.Y, TurretMesh->GetComponentLocation().Z) - TurretMesh->GetComponentLocation()).Rotation());
	
} 

void APawnBase::Fire()
{
	if (ProjectileClass)
	{
		//FVector SpawnPoint = ProjectileSpawnPoint->GetComponentLocation();
		//FRotator SpawnRotation = ProjectileSpawnPoint->GetComponentRotation();		
		AProjectileBase* TempProjectile = GetWorld()->SpawnActor<AProjectileBase>(ProjectileClass, ProjectileSpawnPoint->GetComponentLocation(), ProjectileSpawnPoint->GetComponentRotation());
		TempProjectile->SetOwner(this);
		
	}
}

void APawnBase::HandleDestruction()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, DeathParticle, GetActorLocation());
	UGameplayStatics::SpawnSoundAtLocation(this, DeathSound, GetActorLocation());
	GetWorld()->GetFirstPlayerController()->ClientPlayCameraShake(DeathShake);

}

