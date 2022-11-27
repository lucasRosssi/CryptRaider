// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
  PrimaryComponentTick.bCanEverTick = true;

}

void UTriggerComponent::BeginPlay()
{
  Super::BeginPlay();

}


void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

  if (TriggersMovement && !Mover)
  {
    return;
  }
  if (TriggersRotation && !MyRotator)
  {
    return;
  }

  AActor* Actor = GetTriggableActor();
  if (Actor)
  {
    UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());

    if (Component)
    {
      Component->SetSimulatePhysics(false);
    }

    Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);

    if (TriggersMovement)
    {
      Mover->SetShouldMove(true);
    }

    if (TriggersRotation)
    {
      MyRotator->SetShouldRotate(true);
    }

  }
  else
  {
    if (TriggersMovement)
    {
      Mover->SetShouldMove(false);
    }

    if (TriggersRotation)
    {
      MyRotator->SetShouldRotate(false);
    }
  }
}

void UTriggerComponent::SetMover(UMover* NewMover)
{
  Mover = NewMover;
}

void UTriggerComponent::SetMyRotator(UMyRotator* NewRotator)
{
  MyRotator = NewRotator;
}

AActor* UTriggerComponent::GetTriggableActor() const
{
  TArray<AActor*> Actors;
  GetOverlappingActors(Actors);

  for (AActor* Actor : Actors)
  {
    bool HasAcceptableTag = Actor->ActorHasTag(TriggableActorTag);
    bool IsGrabbed = Actor->ActorHasTag("Grabbed");
    if (HasAcceptableTag && !IsGrabbed)
    {
      return Actor;
    }
  }

  return nullptr;
}

