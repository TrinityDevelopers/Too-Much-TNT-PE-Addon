#pragma once

class PushNotificationMessage;

class AppPlatformListener {
public: 
	virtual ~AppPlatformListener();
	virtual void onLowMemory();
	virtual void onAppPaused();
	virtual void onAppPreSuspended();
	virtual void onAppSuspended();
	virtual void onAppResumed();
	virtual void onAppFocusLost();
	virtual void onAppFocusGained();
	virtual void onAppTerminated();
	virtual void onOperationModeChanged(bool);
	virtual void onPerformanceModeChanged(bool);
	virtual void onPushNotificationReceived(const PushNotificationMessage&);
};