// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EnemySpawnInfo.h"
#include "LevelInfo.generated.h"

UENUM(BlueprintType)
enum ELevelMap {
    STAGE_GENERIC_1X2_E UMETA(DisplayName = "NormalStage_1x2_E"),
    STAGE_GENERIC_2X1_N UMETA(DisplayName = "NormalStage_2x1_N"),
    STAGE_GENERIC_1X2_W UMETA(DisplayName = "NormalStage_1x2_W"),
    STAGE_GENERIC_2X1_S UMETA(DisplayName = "NormalStage_2x1_S"),
    STAGE_SPECIAL_MIS   UMETA(DisplayName = "L0_Miseria")
};

USTRUCT(BlueprintType)
struct FMapStageInfo : public FTableRowBase {
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TEnumAsByte<ELevelMap> Map;

    FMapStageInfo() {
        Map = ELevelMap::STAGE_GENERIC_1X2_E;
    }
};

// Stage is basically spawn info plus stage number
USTRUCT(BlueprintType)
struct FEnemyStageInfo : public FTableRowBase {
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int Stage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TEnumAsByte<EEnemies> EnemyType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int Number;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float MaxHP;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float PrimaryAttackDmg;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        float AggroRange;

    FEnemyStageInfo() {
        Stage = 0;
        Number = 3;
        MaxHP = 100.0f;
        PrimaryAttackDmg = 30.0f;
        AggroRange = 500.0f;
    }
};

USTRUCT(BlueprintType)
struct FEnemySpawnInfoList {
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FEnemySpawnInfo> EnemySpawnInfos;

    FEnemySpawnInfoList() {}
};
