// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine/DeveloperSettings.h"
#include "UObject/SoftObjectPtr.h"

#include "LyraUIMessagingSettings.generated.h"

class UObject;
class UCommonGameDialog;

/**
 * 
 */
UCLASS(config = Game, defaultconfig, meta = (DisplayName = "LyraUIMessagingSettings"))
class LYRAUINAVIGATION_API ULyraUIMessagingSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:

	UPROPERTY(config, EditAnywhere, Category = MessagingSettings)
	TSoftClassPtr<UCommonGameDialog> ConfirmationDialogClass;

	UPROPERTY(config, EditAnywhere, Category = MessagingSettings)
	TSoftClassPtr<UCommonGameDialog> ErrorDialogClass;

private:


};
