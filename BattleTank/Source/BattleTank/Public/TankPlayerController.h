// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"		//must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;

	ATank* GetControlledTank() const;

private:

	void AimTowardsCrosshair();
};
