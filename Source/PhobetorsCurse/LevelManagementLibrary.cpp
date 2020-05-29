// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelManagementLibrary.h"

FEnemySpawnInfo ULevelManagementLibrary::StageToSpawnInfo(FEnemyStageInfo stageInfo) {
    FEnemySpawnInfo f;
    f.EnemyType = stageInfo.EnemyType;
    f.Number = stageInfo.Number;
    f.MaxHP = stageInfo.MaxHP;
    f.PrimaryAttackDmg = stageInfo.PrimaryAttackDmg;
    f.AggroRange = stageInfo.AggroRange;
    return f;
}

TArray<FEnemySpawnInfoList> ULevelManagementLibrary::EnemyStageInfoTableToSpawnInfoByStage(TArray<FEnemyStageInfo> stageInfo) {
    TArray<FEnemySpawnInfoList> result;
    // Handle empty array
    if (stageInfo.Num() == 0) {
        FEnemySpawnInfoList newRow;
        result.Add(newRow);
        return result;
    }

    // Add the placeholders first
    int firstStage = stageInfo[0].Stage;
    for (int i = 0; i < firstStage; i++) {
        FEnemySpawnInfoList newRow;
        result.Add(newRow);
    }

    // Collapse rows with the same Stage into a single array
    for (int i = 0; i < stageInfo.Num();) {
        FEnemySpawnInfoList newRow;
        int currStage = stageInfo[i].Stage;
        while (i < stageInfo.Num() && stageInfo[i].Stage == currStage) {
            FEnemySpawnInfo f = StageToSpawnInfo(stageInfo[i]);
            newRow.EnemySpawnInfos.Add(f);
            i++;
        }

        result.Add(newRow);
    }

    return result;
}
