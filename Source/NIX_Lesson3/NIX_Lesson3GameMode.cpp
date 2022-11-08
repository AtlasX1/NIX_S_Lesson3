// Copyright Epic Games, Inc. All Rights Reserved.

#include "NIX_Lesson3GameMode.h"
#include "NIX_Lesson3Character.h"
#include "UObject/ConstructorHelpers.h"

ANIX_Lesson3GameMode::ANIX_Lesson3GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
