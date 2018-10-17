// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TopDownCharacter.generated.h"

UCLASS()
class TABLETPROJECT_API ATopDownCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATopDownCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Camera)
	class UCameraComponent* Camera;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Camera)
	class USpringArmComponent* CameraBoom;

	UFUNCTION()
	void MoveForward(float Delta);

	UFUNCTION()
	void MoveRight(float Delta);

	UFUNCTION()
	void StartJump(float Delta);

	UFUNCTION()
	void StopJump();

	
	
};
