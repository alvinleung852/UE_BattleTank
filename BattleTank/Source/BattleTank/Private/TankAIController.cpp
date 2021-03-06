// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	/*auto ControlledTank = GetControlledTank();

	if (ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Possessing: %s"), *ControlledTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Not possessing a tank"));
	}

	auto PlayerTank = GetPlayerTank();

	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player tank: %s"), *PlayerTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No player tank found"));
	}*/
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerTank) {
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire();
	}
}


//ATank* ATankAIController::GetControlledTank() const {
//	return Cast<ATank>(GetPawn());
//}
//
//ATank* ATankAIController::GetPlayerTank() const {
//	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
//}