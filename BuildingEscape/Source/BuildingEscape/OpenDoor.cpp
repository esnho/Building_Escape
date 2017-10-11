// Learing via Udemy

#include "OpenDoor.h"

// IMPORTANTE aggiungere questa inclusione per abilitare i metodi della classe AActor
#include "GameFramework/Actor.h"

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

	// The Owning Actor
	AActor* Owner = GetOwner();

	// Log the Door Rotation String
	FString DoorRotation = Owner->GetActorRotation().ToString();
	UE_LOG(LogTemp, Error, TEXT("Door rotation %s"), *DoorRotation);

	// Create a Rotator, it Uses Pitch Yaw Roll, can be confusing, it means (not exactly) x z y
	FRotator NewRotation = Owner->GetActorRotation().Add(0.0f, -45.0f, 0.0f);

	// Set the rotation
	Owner->SetActorRotation(NewRotation);
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

