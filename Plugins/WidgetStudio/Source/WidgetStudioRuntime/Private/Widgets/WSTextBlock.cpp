/* 
* Copyright (c) 2021 THEIA INTERACTIVE.  All rights reserved.
*
* Website: https://theia.io
* Documentation: https://theia-interactive.gitbook.io/widget-studio
* Support: https://support.theia.io
* Marketplace FAQ: https://marketplacehelp.epicgames.com
*/

#include "Widgets/WSTextBlock.h"

void UWidgetStudioTextBlock::SetWrapTextAt(const float InWrapTextAt)
{
	WrapTextAt = InWrapTextAt;
	if (MyTextBlock.IsValid())
	{
		MyTextBlock->SetWrapTextAt(InWrapTextAt);
	}
}

void UWidgetStudioTextBlock::SetWrappingPolicy(const ETextWrappingPolicy InWrappingPolicy)
{
	WrappingPolicy = InWrappingPolicy;
	if (MyTextBlock.IsValid())
	{
		MyTextBlock->SetWrappingPolicy(InWrappingPolicy);
	}
}