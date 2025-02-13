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
#include "WSBase.h"
#include "Components/Image.h"
#include "Components/InvalidationBox.h"
#include "Components/Overlay.h"
#include "Components/ScaleBox.h"
#include "Components/SizeBox.h"

#include "WSModernProgressBar.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWFProgressBarDelegate, float, NewValue);

/**
 * A modern styled progress bar. Useful for display the progress of an event or the percentage of a value.
 */
UCLASS(BlueprintType, Blueprintable)
class WIDGETSTUDIORUNTIME_API UWidgetStudioModernProgressBar : public UWidgetStudioBase
{
	GENERATED_BODY()

protected:

	#if WITH_EDITOR
		virtual const FText GetPaletteCategory() override;
	#endif

	virtual TSharedRef<SWidget> RebuildWidget() override;
	virtual int32 NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	virtual void SynchronizeProperties() override;
	virtual void InitializeStyling() override;
	virtual void UpdateStyling() override;

	/* Internal Properties */
	
	UPROPERTY()
	bool bForwardProgress = true;

	/* Widget Components */

	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
	UInvalidationBox* Retainer = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
	USizeBox* SizeBox = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
	UOverlay* Overlay = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
	UScaleBox* TrackScaleBox = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
	UOverlay* TrackOverlay = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
	UImage* Track = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
	UImage* TrackDropShadow = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
	USizeBox* FillTrackSizeBox = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
	UImage* FillTrack = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
	USizeBox* IndicatorSizeBox = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
	UImage* Indicator = nullptr;


private:
	/* Bindings */

	UPROPERTY(BlueprintAssignable, Category = "Widget Studio|Event")
	FWFProgressBarDelegate OnProgressChanged;
	
	/* Properties */

	// The current progress percent value on a 0-100 scale.
	UPROPERTY(EditAnywhere, Category="Widget Studio", Meta = (ClampMin = "0", ClampMax = "100"))
	float Percent = 50;

	// Display an animated progress direction indicator.
	UPROPERTY(EditAnywhere, Category="Widget Studio")
	bool bDisplayIndicator = true;

	// The color of the track.
	UPROPERTY(EditAnywhere, Category="Widget Studio|Color")
	EPalette TrackColor = EPalette::PrimaryBackground;

	// The color of the fill bar.
	UPROPERTY(EditAnywhere, Category="Widget Studio|Color")
	EPalette FillColor = EPalette::PrimaryAccent;

public:
	
	/* Helpers */

	// Returns the current progress percent.
	UFUNCTION(BlueprintPure, Category="Widget Studio|Helper")
	float GetProgress() const;

	// Is the indicator visible?
	UFUNCTION(BlueprintPure, Category="Widget Studio|Helper")
	bool IsIndicatorVisible() const;

	// Returns the track color
	UFUNCTION(BlueprintPure, Category="Widget Studio|Helper")
	EPalette GetTrackColor() const;

	// Returns the progress fill color
	UFUNCTION(BlueprintPure, Category="Widget Studio|Helper")
	EPalette GetFillColor() const;
	
	/* Modifier Functions */

	// Set the value of the slider.
	UFUNCTION(BlueprintCallable, Category="Widget Studio|Modifier")
	void SetProgress(float NewValue);

	// Enable or disable the indicators visibility.
	UFUNCTION(BlueprintCallable, Category="Widget Studio|Modifier")
	void SetIndicatorVisibility(bool bNewState);

	// Set the color of the track.
	UFUNCTION(BlueprintCallable, Category="Widget Studio|Modifier")
	void SetTrackColor(EPalette NewColor);

	// Set the color of the fill track.
	UFUNCTION(BlueprintCallable, Category="Widget Studio|Modifier")
	void SetFillColor(EPalette NewColor);
};

