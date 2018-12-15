// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "FPSBattlegroundsGameMode.h"
#include "FPSBattlegroundsHUD.h"
#include "FPSBattlegroundsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPSBattlegroundsGameMode::AFPSBattlegroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSBattlegroundsHUD::StaticClass();
}
