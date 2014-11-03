// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseBlankEditor.h"
#include "AssetActions/AssetTypeActions_CharConfig.h"


IMPLEMENT_PRIMARY_GAME_MODULE( EditorModule, BaseBlankEditor, "BaseBlankEditor" );

void EditorModule::StartupModule()
{
    //FModuleManager & moduleManager = FModuleManager::Get();
    IAssetTools & assetTools = FAssetToolsModule::GetModule().Get();
    assetTools.RegisterAssetTypeActions(MakeShareable(new FAssetTypeActions_CharConfig));
    
    UE_LOG(LogTemp, Log, TEXT("Editor Module Startup"));
}

void EditorModule::ShutdownModule() 
{
    UE_LOG(LogTemp, Log, TEXT("Editor Module Shutdown"));
}