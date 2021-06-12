// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

class UProjectileMovementComponent;
class UCameraShake;
UCLASS()
class TOONTANKS_API AProjectileBase : public AActor
{
	GENERATED_BODY()

private:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compopnent", meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Compopnent", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ProjectileMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageType", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UDamageType> DamageType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Movement", meta = (AllowPrivateAccess = "true"))
	float MovementSpeed = 1300.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Movement", meta = (AllowPrivateAccess = "true"))
	float Damage = 50.f;

	float InitialLifeSpan = 3;

	UPROPERTY(EditAnyWhere,Category="Effects")
	UParticleSystem* HitParticle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects", meta = (AllowPrivateAccess = "true"))
	UParticleSystemComponent* ParticleTrail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects", meta = (AllowPrivateAccess = "true"))
	USoundBase* HitSound;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects", meta = (AllowPrivateAccess = "true"))
	USoundBase* LaunchSound;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UCameraShake> HitShake;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent,AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:
	
	// Sets default values for this actor's properties
	AProjectileBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
