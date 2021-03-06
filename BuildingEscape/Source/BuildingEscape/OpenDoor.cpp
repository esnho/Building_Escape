// Learing via Udemy

#include "OpenDoor.h"

// IMPORTANTE aggiungere questa inclusione per abilitare i metodi della classe AActor
#include "GameFramework/Actor.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	ActorThatOpen = GetWorld()->GetFirstPlayerController()->GetPawn();

	// The Owning Actor
	Owner = GetOwner();

	ClosedAngle = Owner->GetActorRotation().Euler().Z;
}

void UOpenDoor::OpenDoor()
{
	// Set the rotation
	Owner->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));
}

void UOpenDoor::CloseDoor()
{
	Owner->SetActorRotation(FRotator(0.f, ClosedAngle, 0.f));
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// If the ActorThat Open is in the volume then open the door
	if (PressurePlate->IsOverlappingActor(ActorThatOpen)) {
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	if ((GetWorld()->GetTimeSeconds() - LastDoorOpenTime) > DoorCloseDelay) {
		CloseDoor();
	}
}

