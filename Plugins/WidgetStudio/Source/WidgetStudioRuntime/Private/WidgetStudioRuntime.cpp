/* 
* Copyright (c) 2021 THEIA INTERACTIVE.  All rights reserved.
*
* Website: https://theia.io
* Documentation: https://theia-interactive.gitbook.io/widget-studio
* Support: https://support.theia.io
* Marketplace FAQ: https://marketplacehelp.epicgames.com
*/

#include "WidgetStudioRuntime.h"

#define LOCTEXT_NAMESPACE "FWidgetStudioRuntime"
DEFINE_LOG_CATEGORY(LogWidgetStudio);

void FWidgetStudioRuntime::StartupModule()
{
}

void FWidgetStudioRuntime::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FWidgetStudioRuntime, WidgetStudioRuntime)
