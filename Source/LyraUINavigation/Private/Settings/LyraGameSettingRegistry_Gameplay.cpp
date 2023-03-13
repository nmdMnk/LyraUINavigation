// Copyright Epic Games, Inc. All Rights Reserved.

#include "Settings/LyraGameSettingRegistry.h"

#include "GameSettings/GameSetting.h"
#include "GameSettings/GameSettingValueDiscreteDynamic.h"
#include "GameSettings/GameSettingValueScalar.h"
#include "GameSettings/GameSettingValueScalarDynamic.h"
#include "GameSettings/GameSettingCollection.h"
#include "GameSettings/GameSettingAction.h"
#include "GameSettings/EditCondition/WhenPlayingAsPrimaryPlayer.h"
#include "Settings/CustomSettings/LyraSettingValueDiscrete_Language.h"
#include "Player/LyraLocalPlayer.h"

#define LOCTEXT_NAMESPACE "Lyra"

UGameSettingCollection* ULyraGameSettingRegistry::InitializeGameplaySettings(ULyraLocalPlayer* InLocalPlayer)
{
	UGameSettingCollection* Screen = NewObject<UGameSettingCollection>();
	Screen->SetDevName(TEXT("GameplayCollection"));
	Screen->SetDisplayName(LOCTEXT("GameplayCollection_Name", "Gameplay"));
	Screen->Initialize(InLocalPlayer);

	{
		UGameSettingCollection* LanguageSubsection = NewObject<UGameSettingCollection>();
		LanguageSubsection->SetDevName(TEXT("LanguageCollection"));
		LanguageSubsection->SetDisplayName(LOCTEXT("LanguageCollection_Name", "Language"));
		Screen->AddSetting(LanguageSubsection);

		//----------------------------------------------------------------------------------
		{
			ULyraSettingValueDiscrete_Language* Setting = NewObject<ULyraSettingValueDiscrete_Language>();
			Setting->SetDevName(TEXT("Language"));
			Setting->SetDisplayName(LOCTEXT("LanguageSetting_Name", "Language"));
			Setting->SetDescriptionRichText(LOCTEXT("LanguageSetting_Description", "The language of the game."));
			
#if WITH_EDITOR
			if (GIsEditor)
			{
				Setting->SetDescriptionRichText(LOCTEXT("LanguageSetting_WithEditor_Description", "The language of the game.\n\n<text color=\"#ffff00\">WARNING: Language changes will not affect PIE, you'll need to run with -game to test this, or change your PIE language options in the editor preferences.</>"));
			}
#endif
			
			Setting->AddEditCondition(FWhenPlayingAsPrimaryPlayer::Get());

			LanguageSubsection->AddSetting(Setting);
		}
		//----------------------------------------------------------------------------------
	}

	return Screen;
}

#undef LOCTEXT_NAMESPACE
