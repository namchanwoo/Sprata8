﻿/* 
* Copyright (c) 2021 THEIA INTERACTIVE.  All rights reserved.
*
* Website: https://theia.io
* Documentation: https://theia-interactive.gitbook.io/widget-studio
* Support: https://support.theia.io
* Marketplace FAQ: https://marketplacehelp.epicgames.com
*/

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WSTheme.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class WIDGETSTUDIORUNTIME_API UWidgetStudioTheme : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Accent", Meta=(HideAlphaChannel="true"))
	FLinearColor PrimaryAccent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Accent", Meta=(HideAlphaChannel="true"))
	FLinearColor SecondaryAccent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Content", Meta=(HideAlphaChannel="true"))
	FLinearColor PrimaryContent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Content", Meta=(HideAlphaChannel="true"))
	FLinearColor SecondaryContent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Content", Meta=(HideAlphaChannel="true"))
	FLinearColor TertiaryContent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Background", Meta=(HideAlphaChannel="true"))
	FLinearColor PrimaryBackground;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Background", Meta=(HideAlphaChannel="true"))
	FLinearColor SecondaryBackground;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Background", Meta=(HideAlphaChannel="true"))
	FLinearColor TertiaryBackground;

private:
	UWidgetStudioTheme();
};
