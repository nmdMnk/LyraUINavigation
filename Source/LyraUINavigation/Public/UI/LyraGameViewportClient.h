// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CommonGameViewportClient.h"
#include "UObject/UObjectGlobals.h"

#include "LyraGameViewportClient.generated.h"

class UGameInstance;
class UObject;

UCLASS(BlueprintType)
class LYRAUINAVIGATION_API ULyraGameViewportClient : public UCommonGameViewportClient
{
	GENERATED_BODY()

public:
	ULyraGameViewportClient();

	virtual void Init(struct FWorldContext& WorldContext, UGameInstance* OwningGameInstance, bool bCreateNewAudioDevice = true) override;
};