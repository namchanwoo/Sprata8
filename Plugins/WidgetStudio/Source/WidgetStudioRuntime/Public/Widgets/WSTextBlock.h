/* 
* Copyright (c) 2021 THEIA INTERACTIVE.  All rights reserved.
*
* Website: https://theia.io
* Documentation: https://theia-interactive.gitbook.io/widget-studio
* Support: https://support.theia.io
* Marketplace FAQ: https://marketplacehelp.epicgames.com
*/

#pragma once

#include "CoreMinimal.h"

#include "Components/TextBlock.h"
#include "Widgets/Text/STextBlock.h"
#include "WSTextBlock.generated.h"

/**
 * A customized TextBlock that exposes SetWrapTextAt() and SetWrappingPolicy() functions
 */
UCLASS()
class WIDGETSTUDIORUNTIME_API UWidgetStudioTextBlock : public UTextBlock
{
	GENERATED_BODY()

public:

	/** See WrapTextAt attribute */
	UFUNCTION(BlueprintCallable, Category = "Text Block")
		void SetWrapTextAt(float InWrapTextAt);


	/** Set WrappingPolicy attribute */
	UFUNCTION(BlueprintCallable, Category = "Text Block")
		void SetWrappingPolicy(ETextWrappingPolicy InWrappingPolicy);

	/*protected:*/
	TSharedPtr<STextBlock> MyTextBlock;
};
