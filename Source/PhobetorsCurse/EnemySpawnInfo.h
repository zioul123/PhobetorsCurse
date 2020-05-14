// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Runtime\Engine\Classes\GameFramework\Character.h>
#include "EnemySpawnInfo.generated.h"

UENUM(BlueprintType)
enum EEnemies {
    SHADOW_KNIGHT       UMETA(DisplayName = "ShadowKnight"),
    SHADOW_WIZARD_F     UMETA(DisplayName = "ShadowWizardF")
};

USTRUCT(BlueprintType)
struct FEnemySpawnInfo {
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TSubclassOf<ACharacter> EnemyType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int Number;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float MaxHP;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float PrimaryAttackDmg;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float AggroRange;

    FEnemySpawnInfo() { 
        Number = 3; 
        MaxHP = 100.0f;
        PrimaryAttackDmg = 30.0f;
        AggroRange = 500.0f;
    }
};

/**
 * 
 */
