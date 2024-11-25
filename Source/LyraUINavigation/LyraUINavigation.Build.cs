// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LyraUINavigation : ModuleRules
{
	public LyraUINavigation(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
			
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"HeadMountedDisplay",
			"EnhancedInput",
            "UMG",
            "CommonUI",
            "GameplayTags"
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "Slate",
            "SlateCore",
            "ApplicationCore",
			"PropertyPath",
            "RHI",
            "GameplayTags",
            "Engine",
            "DeveloperSettings",
            "CommonInput",
            "AudioMixer",
            "AudioModulation",
            "GameSettings",
            "CommonGame",
            "CommonUser"
        });
	}
}
