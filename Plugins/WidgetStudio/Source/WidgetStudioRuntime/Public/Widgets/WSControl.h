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
#include "WSBase.h"
#include "WSControl.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWFControlDelegate, FText, CurrentOption, int32, CurrentIndex);

/**
 * 
 */
UCLASS()
class WIDGETSTUDIORUNTIME_API UWidgetStudioControl : public UWidgetStudioBase
{
	GENERATED_BODY()

protected:
	/* * Bindings */

	UPROPERTY(BlueprintAssignable, Category = "Widget Studio|Event")
	FWFControlDelegate OnCurrentIndexChanged;


private:
	/* Properties  */
    
    // The options available.
    UPROPERTY(EditAnywhere, Category="Widget Studio")
    TArray<FText> Options;

	// The current index of the option selected.
	UPROPERTY(EditAnywhere, Category="Widget Studio")
	int32 CurrentIndex;

public:
	/* Helpers */

	// Returns all of the available options.
	UFUNCTION(BlueprintPure, Category="Widget Studio|Helper")
	TArray<FText> GetOptions() const;

	// Returns the current selected option.
	UFUNCTION(BlueprintPure, Category="Widget Studio|Helper")
	FText GetCurrentOption() const;

	// Returns the option at the given index.
	UFUNCTION(BlueprintPure, Category="Widget Studio|Helper")
	FText GetOptionAtIndex(int32 Index) const;

	// Returns the current selected index.
	UFUNCTION(BlueprintPure, Category="Widget Studio|Helper")
	int32 GetCurrentIndex() const;

	// Returns the number of options.
	UFUNCTION(BlueprintPure, Category="Widget Studio|Helper")
	int32 GetOptionCount() const;

	/* Modifiers */

	// Overrides the current available options.
	UFUNCTION(BlueprintCallable, Category="Widget Studio|Modifier")
	void SetOptions(TArray<FText> NewOptions);

	// Set the selected option.
	UFUNCTION(BlueprintCallable, Category="Widget Studio|Modifier")
	bool SetCurrentIndexViaOption(const FText NewSelectedOption);

	// Overrides the current index.
	UFUNCTION(BlueprintCallable, Category="Widget Studio|Modifier")
	bool SetCurrentIndex(const int32 NewIndex);
};
