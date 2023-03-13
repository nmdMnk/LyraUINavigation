// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameSettings/EditCondition/WhenPlayingAsPrimaryPlayer.h"

#include "Engine/LocalPlayer.h"
#include "GameSettings/GameSettingFilterState.h"
#include "Internationalization/Internationalization.h"

#define LOCTEXT_NAMESPACE "GameSetting"

TSharedRef<FWhenPlayingAsPrimaryPlayer> FWhenPlayingAsPrimaryPlayer::Get()
{
	static TSharedRef<FWhenPlayingAsPrimaryPlayer> Instance = MakeShared<FWhenPlayingAsPrimaryPlayer>();
	return Instance;
}

void FWhenPlayingAsPrimaryPlayer::GatherEditState(const ULocalPlayer* InLocalPlayer, FGameSettingEditableState& InOutEditState) const
{
	if (!InLocalPlayer->IsPrimaryPlayer())
	{
		InOutEditState.Disable(LOCTEXT("OnlyPrimaryPlayerEditable", "Can only be changed by the primary player."));
	}
}

#undef LOCTEXT_NAMESPACE