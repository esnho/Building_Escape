// Learing via Udemy

#include "Grabber.h"

// IMPORTANTE aggiungere questa inclusione per abilitare i metodi della classe AActor
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	FString ObjectName = GetOwner()->GetName();

	UE_LOG(LogTemp, Warning, TEXT("Grabber instatiated onto %s"), *ObjectName);
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get player view point this tick
	FVector PlayerPosition;
	FRotator PlayerRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerPosition, OUT PlayerRotation);

	/*UE_LOG(LogTemp, Warning, TEXT(
		"Player Position %s and rotation %s"), 
		*PlayerPosition.ToString(),
		*PlayerRotation.ToString()
	);*/


	// Draw debugline
	FVector LineTraceEnd = PlayerPosition + (PlayerRotation.Vector() * Reach);
	
	DrawDebugLine(
		GetWorld(),
		PlayerPosition,
		LineTraceEnd,
		FColor(255, 0, 0),
		false,
		0.f,
		0.f,
		1.f
	);

	/*DrawDebugLine
	(
		const UWorld * InWorld,
		FVector const & LineStart,
		FVector const & LineEnd,
		FColor const & Color,
		bool bPersistentLines,
		float LifeTime,
		uint8 DepthPriority,
		float Thickness
	)*/

	// Raycast out to reach distance

	// See what we hit
}

