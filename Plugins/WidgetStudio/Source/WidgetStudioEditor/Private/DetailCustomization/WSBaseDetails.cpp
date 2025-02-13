// "// Copyright (c) 2021 THEIA INTERACTIVE.  All rights reserved."

#include "DetailCustomization/WSBaseDetails.h"
#include "DetailLayoutBuilder.h"

#define LOCTEXT_NAMESPACE "Base Details"

TSharedRef<IDetailCustomization> FModernButtonDetails::MakeInstance()
{
	return MakeShareable(new FModernButtonDetails);
}

void FModernButtonDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	DetailBuilder.EditCategory("Widget Studio", LOCTEXT("CatName", "Widget Studio"), ECategoryPriority::Important);
}

#undef LOCTEXT_NAMESPACE

