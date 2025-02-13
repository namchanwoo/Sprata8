// Copyright Epic Games, Inc. All Rights Reserved.

#include "Free54GameMode.h"
#include "Free54Character.h"
#include "UObject/ConstructorHelpers.h"

AFree54GameMode::AFree54GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
