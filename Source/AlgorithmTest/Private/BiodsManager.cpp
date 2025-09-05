// Fill out your copyright notice in the Description page of Project Settings.


#include "BiodsManager.h"
#include "Engine/StaticMeshActor.h"
#include "BiodsLibrary.h"

void UBiodsManager::Tick(float DeltaTime)
{

}

bool UBiodsManager::IsTickable() const
{
	return IsStarted;
}

TStatId UBiodsManager::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UBiodsManager, STATGROUP_Tickables);
}

ETickableTickType UBiodsManager::GetTickableTickType() const
{
	return ETickableTickType::Always;
}

void UBiodsManager::Init(UStaticMesh* _InstanceMesh, int32 _BiodsNum, FTransform SpawnTransform)
{	
	InstanceMesh=_InstanceMesh;
	BiodsNum=_BiodsNum;
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	for (int32 i = 0; i < BiodsNum; i++)
	{
		FBiod NewBiod;
		if (!UBiodsLibrary::GetLeisureLocation(Biods, NewBiod,SpawnTransform.GetLocation()))
		{
			return;
		}
		AStaticMeshActor* NewInstance=GetWorld()->SpawnActor<AStaticMeshActor>(AStaticMeshActor::StaticClass(),NewBiod.Location,NewBiod.Direction,SpawnParams);
		NewInstance->GetStaticMeshComponent()->SetStaticMesh(InstanceMesh);	
		Biods.Add(NewBiod);
		BiodInstances.Add(NewInstance);
	}
}
