// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "UObject/ObjectMacros.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLECOURSE_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

  // Base Attributes
  FString prefix = "MovingPlatform -";
  float direction = 1.0f;

  // Member functions
  void MovePlatform(float DeltaTime);
  void RotatePlatform(float DeltaTime);

  // Properties
  FVector start_location;

 
  // UI Properties
  UPROPERTY(EditAnywhere)
  float max_distance = 1000;

  UPROPERTY(EditAnywhere)
  float movement_speed = 5.0f;
 
  UPROPERTY(EditAnywhere)
  FVector velocity = FVector(0.0f, 0.0f, 0.0f);

  UPROPERTY(EditAnywhere)
  FRotator r_velocity;
};
