// Copyright Epic Games, Inc. All Rights Reserved.

#include "LyraUINavigationModule.h"

#include "Modules/ModuleManager.h"
#include "GameplayTagsManager.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FLyraUINavigationModule"

void FLyraUINavigationModule::StartupModule()
{
	TSharedPtr<IPlugin> ThisPlugin = IPluginManager::Get().FindPlugin(TEXT("LyraUINavigation"));
	check(ThisPlugin.IsValid());

	// CommonUISettings is loading PlatformTraits from the configuration before these tags are added. As a temporary workaround, all Platform.Trait tags are also defined as GAMEPLAY_TAG_STATIC.
	UGameplayTagsManager::Get().AddTagIniSearchPath(ThisPlugin->GetBaseDir() / TEXT("Config") / TEXT("Tags"));
}

void FLyraUINavigationModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FLyraUINavigationModule, LyraUINavigation)