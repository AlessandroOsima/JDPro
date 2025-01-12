// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "JDBlueprintFunctionLibrary.generated.h"


class UDamageInfo;
/**
 * 
 */
UCLASS()
class BASEBLANK_API UJDBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

    UFUNCTION(BlueprintCallable, Category="JD,Global Functions")
    static UDamageInfo * CreateDamageInfo();
	
};
