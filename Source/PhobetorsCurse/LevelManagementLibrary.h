// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LevelManagementLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PHOBETORSCURSE_API ULevelManagementLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
        UFUNCTION(BlueprintCallable, Category = "LevelManagement")
        static FString HelloWorld(int a, int b);
};
