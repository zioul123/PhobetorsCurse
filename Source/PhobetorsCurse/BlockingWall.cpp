// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockingWall.h"

// Sets default values
ABlockingWall::ABlockingWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
}

// Called when the game starts or when spawned
void ABlockingWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABlockingWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

