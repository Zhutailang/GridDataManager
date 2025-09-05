// Fill out your copyright notice in the Description page of Project Settings.


#include "BiodsLibrary.h"

FVector UBiodsLibrary::Seperation(TArray<FBiod> Biods, FBiod target)
{
	FVector targetDirection=FVector(0);
	for (auto it : Biods)
	{
		targetDirection+=it.Location;
	}
	return targetDirection;
}

FRotator UBiodsLibrary::Alignment(TArray<FBiod> Biods, FBiod target)
{
	FQuat CombineQuat=FQuat::Identity;
	for (auto it : Biods)
	{
		CombineQuat+=it.Direction.Quaternion();
	}
	CombineQuat/=Biods.Num();
	CombineQuat.Normalize();
	return CombineQuat.Rotator();
}

FVector UBiodsLibrary::Cohesion(TArray<FBiod> Biods, FBiod target)
{
	FVector targetDirection=FVector(0);
	for (auto it : Biods)
	{
		targetDirection+=it.Location;
	}
	return targetDirection/Biods.Num();
}

bool UBiodsLibrary::GetLeisureLocation(TArray<FBiod> Biods,FBiod targetBiod, FVector SpawnLoc, float SpawnRadius,float DistanceFiled)
{
	return true;
}

bool FLocationTreeNode::Insert(FBiod NewBiod)
{
	if (Points.Num() == 0)
	{
		
	}
	return false;
}

int32 FLocationTreeNode::GetIndex(FBiod NewBiod)
{
	int32 Index=-1;
	bool Top;
	bool Forward;
	bool Right;
	if (NewBiod.Location.X<(Location.X+Range.X)&&NewBiod.Location.X>(Location.X-Range.X))
	{
		Forward=NewBiod.Location.X>Location.X;
	}
	else return Index;
	if(NewBiod.Location.Y<(Location.Y+Range.Y)&&NewBiod.Location.Y>(Location.Y-Range.Y))
	{
		Right=NewBiod.Location.Y>Location.Y;
	}
	else return Index;
	if(NewBiod.Location.Z<(Location.Z+Range.Z)&&NewBiod.Location.Z>(Location.Z-Range.Z))
	{
		Top=NewBiod.Location.Z>Location.Z;
	}
	else return Index;
	if (Top)
	{
		if (Forward)
		{
			if (Right)	Index=0; //右前上
			else Index=1; //左前上
		}
		else
		{
			if(Right) Index=2; //右后上
			else Index=3; //左后上
		}
	}
	else
	{
		if (Forward)
		{
			if(Right) Index=4; //右前下
			else Index=5; //左前下
		}
		else
		{
			if(Right) Index=6; //右后下
			else Index=7; //左后下
		}
	}
	return Index;
}

bool FLocationTreeNode::TrySplit()
{
	return false;
}

void FLocationTreeNode::Split()
{

}

void FLocationTreeNode::Clear()
{

}

TArray<FBiod> FLocationTreeNode::Retrieve(FVector _Location)
{
	TArray<FBiod> Temp;
	return Temp;
}
