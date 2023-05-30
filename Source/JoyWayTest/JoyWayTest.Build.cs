// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class JoyWayTest : ModuleRules
{
	public JoyWayTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
		
		PublicIncludePaths.AddRange(new string[]
		{
			"JoyWayTest/Public",
			"JoyWayTest/Public/Core"
		});
	}
}

