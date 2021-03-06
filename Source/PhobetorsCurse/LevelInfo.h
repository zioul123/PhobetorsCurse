// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EnemySpawnInfo.h"
#include "LevelInfo.generated.h"

UENUM(BlueprintType)
enum ELevelMap {
    // Generic Combat Levels, for testing
    NormalStage_1x2_E UMETA(DisplayName = "NormalStage_1x2_E"),
    NormalStage_2x1_N UMETA(DisplayName = "NormalStage_2x1_N"),
    NormalStage_1x2_W UMETA(DisplayName = "NormalStage_1x2_W"),
    NormalStage_2x1_S UMETA(DisplayName = "NormalStage_2x1_S"),
    L0_Miseria        UMETA(DisplayName = "L0_Miseria"),

    // Physical world and main menu
    PhysicalMansion   UMETA(DisplayName = "PhysicalMansion"),
    MainMenu          UMETA(DisplayName = "MainMenu"),

    // Level 0 - The Dream Realm
    L00_00_Nightmare UMETA(DisplayName = "L00_00_Nightmare"),
    L00_01_Nightmare UMETA(DisplayName = "L00_01_Nightmare"),
    L00_02_Nightmare UMETA(DisplayName = "L00_02_Nightmare"),
    L00_03_Nightmare UMETA(DisplayName = "L00_03_Nightmare"),
    L00_04_Nightmare UMETA(DisplayName = "L00_04_Nightmare"),
    L00_05_Nightmare UMETA(DisplayName = "L00_05_Nightmare")
};

UENUM(BlueprintType)
enum ELevels {
    // Generic Combat Levels, for testing
    Level0  UMETA(DisplayName = "Level0"),
    Level1  UMETA(DisplayName = "Level1"),
    Level2  UMETA(DisplayName = "Level2"),
    Level3  UMETA(DisplayName = "Level3"),
    Level4  UMETA(DisplayName = "Level4"),
    Level5  UMETA(DisplayName = "Level5"),
    Level6  UMETA(DisplayName = "Level6"),
    Level7  UMETA(DisplayName = "Level7"),
    Level8  UMETA(DisplayName = "Level8"),
    Level9  UMETA(DisplayName = "Level9"),
    Level10 UMETA(DisplayName = "Level10"),
    Level11 UMETA(DisplayName = "Level11")
};

USTRUCT(BlueprintType)
struct FMapStageInfo : public FTableRowBase {
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TEnumAsByte<ELevelMap> Map;

    FMapStageInfo() {
        Map = ELevelMap::NormalStage_1x2_E;
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
