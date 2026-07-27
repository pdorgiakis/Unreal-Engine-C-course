// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include "Math/MathFwd.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

  start_location = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

  MovePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
  FVector loc_vector = GetActorLocation();

  loc_vector = loc_vector + velocity * DeltaTime;
  SetActorLocation(loc_vector);

  float moving_distance = FVector::Dist(loc_vector, start_location);

  if (moving_distance >= max_distance) {
    FVector move_direction = velocity.GetSafeNormal();
    FVector new_start_location = start_location + move_direction * moving_distance;
    SetActorLocation(new_start_location);
    start_location = new_start_location;

    velocity = -velocity;
  }
}

