// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRadioOverlap.h"

#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"


AMyRadioOverlap::AMyRadioOverlap()
{
	this->Audio->bAutoActivate = false;
	
	static ConstructorHelpers::FObjectFinder<USoundCue> orkTankSoundCueObject(TEXT("/Game/StarterContent/Audio/Fire01_Cue.Fire01_Cue"));
	if(orkTankSoundCueObject.Succeeded())
	{
		OrkTankSoundCue = orkTankSoundCueObject.Object;

	}
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(this->StaticMesh);
	
}

void AMyRadioOverlap::BeginPlay()
{
	Super::BeginPlay();

	BoxCollision->SetHiddenInGame(false);
	BoxCollision->SetBoxExtent(FVector(30.f, 30.f, 30.f));
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AMyRadioOverlap::OnOverlapBegin);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &AMyRadioOverlap::OnOverlapEnd);
	this->Audio->SetSound(OrkTankSoundCue);
	this->Audio->Activate();
	this->Pause(true);

}


void AMyRadioOverlap::OnOverlapBegin(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int otherBodyIndex, bool fromSweep, const FHitResult& sweepResult)
{

	if (otherActor == GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		GEngine->AddOnScreenDebugMessage(-1,200,FColor::Green,TEXT("No pause"));
		this->Pause(false);

	}
}

void AMyRadioOverlap::OnOverlapEnd(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int otherBodyIndex)
{

	if (otherActor == GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		GEngine->AddOnScreenDebugMessage(-1,200,FColor::Green,TEXT("Pause"));

		this->Pause(true);
	}
}