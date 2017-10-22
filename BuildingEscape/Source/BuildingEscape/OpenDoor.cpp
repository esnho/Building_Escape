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
}

void UOpenDoor::OpenDoor()
{
	// The Owning Actor
	AActor* Owner = GetOwner();

	FRotator NewRotation = FRotator(0.f, OpenAngle, 0.f);

	// Set the rotation
	Owner->SetActorRotation(NewRotation);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// If the ActorThat Open is in the volume then open the door
	if (PressurePlate->IsOverlappingActor(ActorThatOpen)) {
		OpenDoor();
	}
}

