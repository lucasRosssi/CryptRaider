// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRotator.h"

// Sets default values for this component's properties
UMyRotator::UMyRotator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


}


// Called when the game starts
void UMyRotator::BeginPlay()
{
	Super::BeginPlay();

  OriginalRotation = GetOwner()->GetActorRotation();
	
}


// Called every frame
void UMyRotator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

  FRotator TargetRotation = OriginalRotation;
  if (ShouldRotate)
  {
    TargetRotation = OriginalRotation + RotationOffset;
  }

  FRotator CurrentRotation = GetOwner()->GetActorRotation();

  FRotator NewRotation = FMath::RInterpConstantTo(CurrentRotation, TargetRotation, DeltaTime, RotateSpeed);
  GetOwner()->SetActorRotation(NewRotation);

}

void UMyRotator::SetShouldRotate(bool NewShouldRotate)
{
  ShouldRotate = NewShouldRotate;
}

FRotator UMyRotator::GetRotationOffset() const
{
  return RotationOffset;
}

