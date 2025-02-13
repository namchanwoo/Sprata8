﻿/* 
* Copyright (c) 2021 THEIA INTERACTIVE.  All rights reserved.
*
* Website: https://theia.io
* Documentation: https://theia-interactive.gitbook.io/widget-studio
* Support: https://support.theia.io
* Marketplace FAQ: https://marketplacehelp.epicgames.com
*/


#include "Widgets/WSDivider.h"

#include "Blueprint/WidgetTree.h"
#include "Components/OverlaySlot.h"
#include "Components/ScaleBoxSlot.h"
#include "Components/SizeBoxSlot.h"

#define LOCTEXT_NAMESPACE "WidgetStudio"

#if WITH_EDITOR
const FText UWidgetStudioDivider::GetPaletteCategory()
{
	return LOCTEXT("WidgetStudio", "*Widget Studio - Utility");
}
#endif

#undef LOCTEXT_NAMESPACE

TSharedRef<SWidget> UWidgetStudioDivider::RebuildWidget()
{
	UPanelWidget* RootWidget = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("RootWidget"));
	WidgetTree->RootWidget = RootWidget;
	
	TSharedRef<SWidget> Widget = Super::RebuildWidget();

	if (RootWidget && WidgetTree)
	{
		
		/* Construct Widgets */
		SpaceAllocation = WidgetTree->ConstructWidget<UOverlay>(UOverlay::StaticClass(), TEXT("Space Allocation"));
		SizeBox = WidgetTree->ConstructWidget<USizeBox>(USizeBox::StaticClass(), TEXT("Size Box"));
		ScaleBox = WidgetTree->ConstructWidget<UScaleBox>(UScaleBox::StaticClass(), TEXT("Scale Box"));
		ImageItem = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), TEXT("Image Item"));

			
		/* Construct Hierarchy */
		RootWidget->AddChild(SpaceAllocation);
		SpaceAllocation->AddChild(SizeBox);
		SizeBox->AddChild(ScaleBox);
		ScaleBox->AddChild(ImageItem);

		// Make the image not hit testable by default.
		RootWidget->SetVisibility(ESlateVisibility::HitTestInvisible);

		// Additional Construction Parameters
		bCanOverrideDimensions = false;

		InitializeStyling();
	}
	return Widget;
}

int32 UWidgetStudioDivider::NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry,
	const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId,
	const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	if (!bDisablePainting)
	{
		// Adjusts icon color
		UWidgetStudioFunctionLibrary::InterpImageColor(ImageItem, Color, AnimationTime);

		// Adjust opacity
		UWidgetStudioFunctionLibrary::InterpWidgetOpacity(ImageItem, Opacity, AnimationTime);
	}
	return LayerId;
}

void UWidgetStudioDivider::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	UpdateStyling();
}

void UWidgetStudioDivider::InitializeStyling()
{
	Super::InitializeStyling();

	// Setup Size Box
	Cast<UOverlaySlot>(SizeBox->Slot)->SetHorizontalAlignment(HAlign_Fill);
	Cast<UOverlaySlot>(SizeBox->Slot)->SetVerticalAlignment(VAlign_Fill);

	ScaleBox->SetStretch(EStretch::ScaleToFit);
	Cast<USizeBoxSlot>(ScaleBox->Slot)->SetHorizontalAlignment(HAlign_Fill);
	Cast<USizeBoxSlot>(ScaleBox->Slot)->SetVerticalAlignment(VAlign_Fill);
	Cast<UScaleBoxSlot>(ImageItem->Slot)->SetHorizontalAlignment(HAlign_Fill);
	Cast<UScaleBoxSlot>(ImageItem->Slot)->SetVerticalAlignment(VAlign_Fill);

	// Setup ImageItem
	ImageItem->SetBrushFromMaterial(UWidgetStudioFunctionLibrary::GetRoundedBackgroundMaterial());
	ImageItem->Brush.DrawAs = ESlateBrushDrawType::Box;
	ImageItem->Brush.Margin = FMargin(0.5);
}

void UWidgetStudioDivider::UpdateStyling()
{
	Super::UpdateStyling();

	if (SizeBox)
	{
		if (Orientation == Orient_Horizontal)
		{
			SizeBox->SetWidthOverride(Length);
			SizeBox->SetHeightOverride(Thickness);
			Cast<UOverlaySlot>(SizeBox->Slot)->SetPadding(FMargin(0, LeadingSpace, 0, TrailingSpace));
		}
		else
		{
			SizeBox->SetWidthOverride(Thickness);
			SizeBox->SetHeightOverride(Length);
			Cast<UOverlaySlot>(SizeBox->Slot)->SetPadding(FMargin(LeadingSpace, 0, TrailingSpace, 0));
			
		}
	}

	if (ImageItem)
	{
		if (bDisablePainting)
		{
			ImageItem->SetColorAndOpacity(UWidgetStudioFunctionLibrary::GetColorFromPalette(Color));
			ImageItem->SetRenderOpacity(Opacity);
		}
		ImageItem->SetBrushSize(FVector2D(Thickness, Thickness));
		ImageItem->Brush.SetImageSize(FVector2D(Thickness, Thickness));
	}
}

TEnumAsByte<EOrientation> UWidgetStudioDivider::GetOrientation() const
{
	return Orientation;
}

float UWidgetStudioDivider::GetThickness() const
{
	return Thickness;
}

float UWidgetStudioDivider::GetLength() const
{
	return Length;
}

float UWidgetStudioDivider::GetOpacity() const
{
	return Opacity;
}

float UWidgetStudioDivider::GetLeadingSpace() const
{
	return LeadingSpace;
}

float UWidgetStudioDivider::GetTrailingSpace() const
{
	return TrailingSpace;
}

void UWidgetStudioDivider::SetLeadingSpace(const float NewValue)
{
	LeadingSpace = NewValue;
	SynchronizeProperties();
}

void UWidgetStudioDivider::SetTrailingSpace(const float NewValue)
{
	TrailingSpace = NewValue;
	SynchronizeProperties();
}

EPalette UWidgetStudioDivider::GetColor() const
{
	return Color;
}

void UWidgetStudioDivider::SetOrientation(const TEnumAsByte<EOrientation> NewOrientation)
{
	Orientation = NewOrientation;
	SynchronizeProperties();
}

void UWidgetStudioDivider::SetThickness(const float NewValue)
{
	Thickness = NewValue;
	SynchronizeProperties();
}

void UWidgetStudioDivider::SetLength(const float NewValue)
{
	Length = NewValue;
	SynchronizeProperties();
}

void UWidgetStudioDivider::SetOpacity(const float NewValue)
{
	Opacity = NewValue;
	SynchronizeProperties();
}

void UWidgetStudioDivider::SetColor(const EPalette NewColor)
{
	Color = NewColor;
	SynchronizeProperties();
}
