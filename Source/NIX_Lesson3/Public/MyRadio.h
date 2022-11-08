// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Radio.h"
#include "MyRadio.generated.h"

/**
 * 
 */
UCLASS()
class NIX_LESSON3_API AMyRadio : public ARadio
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Audio, meta=(AllowPrivateAccess="True"));
	class USoundCue* OrkTankSoundCue;
	
	public:
	AMyRadio();
	protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
