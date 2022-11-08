// Fill out your copyright notice in the Description page of Project Settings.


#include "NIX_Lesson3/Public/MyRadio.h"

#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"


AMyRadio::AMyRadio()
{
	this->Audio->bAutoActivate = false;
	
	static ConstructorHelpers::FObjectFinder<USoundCue> orkTankSoundCueObject(TEXT("/Game/StarterContent/Audio/Fire01_Cue.Fire01_Cue"));
	if(orkTankSoundCueObject.Succeeded())
	{
		OrkTankSoundCue = orkTankSoundCueObject.Object;
	}
	
}


void AMyRadio::BeginPlay()
{
		Super::BeginPlay();

		this->Audio->SetSound(OrkTankSoundCue);
		this->Audio->Play();
}
