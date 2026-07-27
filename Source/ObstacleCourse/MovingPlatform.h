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
  
  // Moving the platform
  void MovePlatform(float DeltaTime);

  // Rotate the platform
  void RotatePlatform(float DeltaTime);

  FVector start_location;

  float direction = 1.0f;

  UPROPERTY(EditAnywhere)
  float max_distance = 1000;

  UPROPERTY(EditAnywhere)
  float movement_speed = 5.0f;
  
  UPROPERTY(EditAnywhere)
  FVector velocity = FVector(0.0f, 0.0f, 0.0f);

  UPROPERTY(EditAnywhere)
  FVector r_velocity = FVector(0.0f, 0.0f, 0.0f);
};
