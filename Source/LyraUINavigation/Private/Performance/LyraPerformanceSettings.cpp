// Copyright Epic Games, Inc. All Rights Reserved.

#include "Performance/LyraPerformanceSettings.h"

#include "Engine/PlatformSettings.h"
#include "Engine/PlatformSettingsManager.h"
#include "Misc/AssertionMacros.h"
#include "Misc/EnumRange.h"
#include "UObject/NameTypes.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(LyraPerformanceSettings)

//////////////////////////////////////////////////////////////////////

ULyraPlatformSpecificRenderingSettings::ULyraPlatformSpecificRenderingSettings()
{
	MobileFrameRateLimits.Append({ 20, 30, 45, 60, 90, 120 });
}

const ULyraPlatformSpecificRenderingSettings* ULyraPlatformSpecificRenderingSettings::Get()
{
	ULyraPlatformSpecificRenderingSettings* Result = UPlatformSettingsManager::Get().GetSettingsForPlatform<ThisClass>();
	check(Result);
	return Result;
}

//////////////////////////////////////////////////////////////////////

ULyraPerformanceSettings::ULyraPerformanceSettings()
{
	PerPlatformSettings.Initialize(ULyraPlatformSpecificRenderingSettings::StaticClass());

	CategoryName = TEXT("Game");

	DesktopFrameRateLimits.Append({ 30, 60, 120, 144, 160, 165, 180, 200, 240, 360 });
}

