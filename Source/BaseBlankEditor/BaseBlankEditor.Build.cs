// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class BaseBlankEditor : ModuleRules
{
	public BaseBlankEditor(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore", "Core", "CoreUObject", "Engine", "InputCore", "AIModule", "AssetTools", "BaseBlank", "UnrealEd" });

		PrivateDependencyModuleNames.AddRange(new string[] { "AssetTools", "UnrealEd" });

		//Uncomment if you are using Slate UI
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore"});

        PrivateIncludePaths.Add( "./AssetActions/" );

        PrivateIncludePathModuleNames.AddRange(
         new string[] {"Slate","SlateCore"});

        PublicIncludePathModuleNames.AddRange(
        new string[] {"Slate","SlateCore"});

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");
		// if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
		// {
		//		if (UEBuildConfiguration.bCompileSteamOSS == true)
		//		{
		//			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
		//		}
		// }
	}
}
