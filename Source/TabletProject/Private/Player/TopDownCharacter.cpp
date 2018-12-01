// Fill out your copyright notice in the Description page of Project Settings.

#include "TopDownCharacter.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
ATopDownCharacter::ATopDownCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setting up the spring arm for the camera.
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true;
	CameraBoom->TargetArmLength = 1250.f;
	CameraBoom->bEnableCameraLag = true;
	CameraBoom->bEnableCameraRotationLag = true;
	CameraBoom->CameraLagSpeed = 10.f;
	CameraBoom->RelativeRotation = FRotator(-10.f, 0.f, 0.f);
	CameraBoom->bDoCollisionTest = false;

	// Attach the camera to the boom.
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	GetCharacterMovement()->JumpZVelocity = 600.f;

	

}

// Called when the game starts or when spawned
void ATopDownCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATopDownCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATopDownCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ATopDownCharacter::MoveForward);
	// PlayerInputComponent->BindAxis("MoveRight", this, &ATopDownCharacter::MoveRight);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ATopDownCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ATopDownCharacter::StopJump);
}

void ATopDownCharacter::MoveForward(float Delta)
{
	FVector Direction = FRotationMatrix(GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Delta);
}

void ATopDownCharacter::MoveRight(float Delta)
{
	FVector Direction = FRotationMatrix(GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Delta);
}

void ATopDownCharacter::StartJump()
{
	bPressedJump = true;
}

void ATopDownCharacter::StopJump()
{
	bPressedJump = false;
}

