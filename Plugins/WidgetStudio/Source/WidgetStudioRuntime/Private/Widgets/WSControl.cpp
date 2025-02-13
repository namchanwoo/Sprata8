/* 
* Copyright (c) 2021 THEIA INTERACTIVE.  All rights reserved.
*
* Website: https://theia.io
* Documentation: https://theia-interactive.gitbook.io/widget-studio
* Support: https://support.theia.io
* Marketplace FAQ: https://marketplacehelp.epicgames.com
*/


#include "Widgets/WSControl.h"

TArray<FText> UWidgetStudioControl::GetOptions() const
{
	return Options;
}

FText UWidgetStudioControl::GetCurrentOption() const
{
	return Options[CurrentIndex];
}

FText UWidgetStudioControl::GetOptionAtIndex(const int32 Index) const
{
	return Options[Index];
}

int32 UWidgetStudioControl::GetCurrentIndex() const
{
	return CurrentIndex;
}

int32 UWidgetStudioControl::GetOptionCount() const
{
	return Options.Num();
}

void UWidgetStudioControl::SetOptions(const TArray<FText> NewOptions)
{
	Options = NewOptions;
}

bool UWidgetStudioControl::SetCurrentIndexViaOption(const FText NewSelectedOption)
{
	//const int32 FindOption = Options.Find(NewSelectedOption);
	//if (FindOption != INDEX_NONE)
	//{
	//	CurrentIndex = FindOption;
	//	OnCurrentIndexChanged.Broadcast(GetCurrentOption(), GetCurrentIndex());	
	//}
	
	//return FindOption != INDEX_NONE;
	return false;
}

bool UWidgetStudioControl::SetCurrentIndex(const int32 NewIndex)
{
	//const bool bIndexAvailable = -1 < NewIndex && NewIndex > Options.Num();
	//if (bIndexAvailable)
	//{
	//	CurrentIndex = NewIndex;
	//	OnCurrentIndexChanged.Broadcast(GetCurrentOption(), GetCurrentIndex());	
	//}
//
	//return bIndexAvailable;
	return false;
}
