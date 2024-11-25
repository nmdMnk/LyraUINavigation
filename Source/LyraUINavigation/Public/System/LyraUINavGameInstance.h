// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CommonGameInstance.h"

#include "LyraUINavGameInstance.generated.h"

UCLASS(Config = Game)
class LYRAUINAVIGATION_API ULyraUINavGameInstance : public UCommonGameInstance
{
	GENERATED_BODY()

public:
	ULyraUINavGameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};