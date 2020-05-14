// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelManagementLibrary.h"

FString ULevelManagementLibrary::HelloWorld(int a, int b) {
    int foo = a + b;
    return FString::Printf(TEXT("Our message is %d"), foo);
}
