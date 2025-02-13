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
#include "Modules/ModuleInterface.h"
#include "WSSettings.h"

class FWidgetStudioEditor final : public IModuleInterface
{

public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual bool SupportsDynamicReloading() override;

	UWidgetStudioSettings* WfSettings;

private:
	void VerifyWidgetStudioInCookDirs() const;
	bool HandleSettingsSaved() const;
	void RegisterSettings() const;
	void UnregisterSettings() const;

	/* Registers all of the detail customizations for Widget Studio */
	void RegisterDetailCustomization() const;

	/* Unregisters all of the detail customizations for Widget Studio */
	void UnregisterDetailCustomization() const;
	
	static TSharedPtr< class FSlateStyleSet > StyleSet;

};