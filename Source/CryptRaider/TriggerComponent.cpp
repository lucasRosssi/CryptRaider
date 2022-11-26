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

  AActor* Actor = GetTriggableActor();
  if (Actor)
  {
    UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
    if (Component)
    {
      Component->SetSimulatePhysics(false);
    }
    Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
    Mover->SetShouldMove(true);
  }
  else
  {
    Mover->SetShouldMove(false);
  }
}

void UTriggerComponent::SetMover(UMover* NewMover)
{
  Mover = NewMover;
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

