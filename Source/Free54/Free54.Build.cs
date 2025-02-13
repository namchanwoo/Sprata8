// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Free54 : ModuleRules
{
	public Free54(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
