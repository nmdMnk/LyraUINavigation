// Copyright Epic Games, Inc. All Rights Reserved.

#include "Input/LyraInputComponent.h"

#include "Containers/Map.h"
#include "EnhancedInputSubsystems.h"
#include "Input/LyraMappableConfigPair.h"
#include "InputCoreTypes.h"
#include "Engine/LocalPlayer.h"
#include "Settings/LyraSettingsLocal.h"
#include "UObject/NameTypes.h"
#include "UObject/UnrealNames.h"
#include "Player/LyraLocalPlayer.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(LyraInputComponent)

class ULyraInputConfig;

ULyraInputComponent::ULyraInputComponent(const FObjectInitializer& ObjectInitializer)
{
}

void ULyraInputComponent::AddInputMappings(const ULyraInputConfig* InputConfig, UEnhancedInputLocalPlayerSubsystem* InputSubsystem) const
{
	check(InputConfig);
	check(InputSubsystem);

	ULyraLocalPlayer* LocalPlayer = InputSubsystem->GetLocalPlayer<ULyraLocalPlayer>();
	check(LocalPlayer);

	// Add any registered input mappings from the settings!
	if (ULyraSettingsLocal* LocalSettings = ULyraSettingsLocal::Get())
	{	
		// Tell enhanced input about any custom keymappings that the player may have customized
		for (const TPair<FName, FKey>& Pair : LocalSettings->GetCustomPlayerInputConfig())
		{
			if (Pair.Key != NAME_None && Pair.Value.IsValid())
			{
				InputSubsystem->AddPlayerMappedKey(Pair.Key, Pair.Value);
			}
		}
	}
}

void ULyraInputComponent::RemoveInputMappings(const ULyraInputConfig* InputConfig, UEnhancedInputLocalPlayerSubsystem* InputSubsystem) const
{
	check(InputConfig);
	check(InputSubsystem);

	ULyraLocalPlayer* LocalPlayer = InputSubsystem->GetLocalPlayer<ULyraLocalPlayer>();
	check(LocalPlayer);
	
	if (ULyraSettingsLocal* LocalSettings = ULyraSettingsLocal::Get())
	{
		// Remove any registered input contexts
		const TArray<FLoadedMappableConfigPair>& Configs = LocalSettings->GetAllRegisteredInputConfigs();
		for (const FLoadedMappableConfigPair& Pair : Configs)
		{
			InputSubsystem->RemovePlayerMappableConfig(Pair.Config);
		}
		
		// Clear any player mapped keys from enhanced input
		for (const TPair<FName, FKey>& Pair : LocalSettings->GetCustomPlayerInputConfig())
		{
			InputSubsystem->RemovePlayerMappedKey(Pair.Key);
		}
	}
}

void ULyraInputComponent::RemoveBinds(TArray<uint32>& BindHandles)
{
	for (uint32 Handle : BindHandles)
	{
		RemoveBindingByHandle(Handle);
	}
	BindHandles.Reset();
}
