// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BiodsLibrary.generated.h"

/**
 * 
 */

struct FLocationTreeNode
{
	FVector Location;
	FVector Range;
	int32 ManageNumber=10;
	TArray<FBiod> Points;
	TArray<FLocationTreeNode*> ChildNodes;

public:
	bool Insert(FBiod NewBiod);
	int32 GetIndex(FBiod NewBiod);
	bool TrySplit();
	void Split();
	void Clear();
	TArray<FBiod> Retrieve(FVector _Location);
};

USTRUCT(BlueprintType)
struct FBiod
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int32 id;
	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly)
	FVector Location;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FRotator Direction;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	float ViewAngle=90;//range:{0,90}
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	bool forwardTrend=false;
	UPROPERTY(BlueprintReadWrite)
	float Radius=100;

	TArray<FBiod> nearBiods;
};

UCLASS()
class ALGORITHMTEST_API UBiodsLibrary : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	static FVector Seperation(TArray<FBiod> Biods,FBiod target);

	UFUNCTION(BlueprintCallable)
	static FRotator Alignment(TArray<FBiod> Biods, FBiod target);

	UFUNCTION(BlueprintCallable)
	static FVector Cohesion(TArray<FBiod> Biods, FBiod target);

	UFUNCTION(BlueprintCallable)
	static bool GetLeisureLocation(TArray<FBiod> Biods,FBiod targetBiod, FVector SpawnLoc,float SpawnRadius = 200.f, float DistanceFiled = 20.f);
};
