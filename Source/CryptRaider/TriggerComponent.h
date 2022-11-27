// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Mover.h"
#include "MyRotator.h"
#include "TriggerComponent.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
  UTriggerComponent();

protected:
  virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

  UFUNCTION(BlueprintCallable)
  void SetMover(UMover* Mover);

  UFUNCTION(BlueprintCallable)
  void SetMyRotator(UMyRotator* MyRotator);

private:
  UPROPERTY(EditAnywhere)
  FName TriggableActorTag;
  UPROPERTY(EditAnywhere)
  bool TriggersRotation = false;
  UPROPERTY(EditAnywhere)
  bool TriggersMovement = false;
  
  UMover* Mover;

  UMyRotator* MyRotator;

  AActor* GetTriggableActor() const;
};
