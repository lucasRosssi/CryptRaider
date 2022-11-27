// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyRotator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UMyRotator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyRotator();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

  UFUNCTION(BlueprintCallable)
  FRotator GetRotationOffset() const;

  void SetShouldRotate(bool ShouldRotate);

private:
  UPROPERTY(EditAnywhere)
  FRotator RotationOffset;

  UPROPERTY(EditAnywhere)
  float RotateSpeed = 10.f;

  bool ShouldRotate = false;

  FRotator OriginalRotation;
		
};
