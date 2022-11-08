// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NIX_Lesson3 : ModuleRules
{
	public NIX_Lesson3(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
