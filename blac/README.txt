  
Thank you for taking the time to download and read my boring instructions
  
  
  Important Info
-----------------
BLAC is very buggy and the being due to the software at hand and my laziness

1. You can only use C++11 no higher (Android r9 can only use C++11 and is the most stable one)
	APP_CPPFLAGS += -std=c++11 (in Application.mk, make sure your's looks like this)
2. You need to edit Android.mk to look similar to this (* is important)
	
	 LOCAL_PATH := $(call my-dir)

	 include $(CLEAR_VARS)

	*define walk
	*  $(wildcard $(1)) $(foreach e, $(wildcard $(1)/*), $(call walk, $(e)))
	*endef

	*ALLFILES = $(call walk, $(LOCAL_PATH))
	*FILE_LIST := $(filter %.cpp, $(ALLFILES))

	 LOCAL_MODULE    := smartdev.exnihilope
	*LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)
	 LOCAL_LDLIBS := -L$(LOCAL_PATH)/libs/$(TARGET_ARCH_ABI) -llog -ldl -lminecraftpe -lmcpelauncher_tinysubstrate -lmcpelauncher_new

	 TARGET_NO_UNDEFINED_LDFLAGS :=

	 include $(BUILD_SHARED_LIBRARY)

3. Once you complete the setup you just have to run blac when you want to compile
4. NEVER EVER EDIT/DELETE "path.txt" or you will have played yourself

   Pre-requisets
------------------
Before we start you need several files and those being the Android NDK, 
Android SDK, Apache Ant and Java Development Kit.

Download Links:
Android NDK (r9, link downloads it) - (32bit): http://dl.google.com/android/ndk/android-ndk-r9d-windows-x86_64.zip (64bit): http://dl.google.com/android/ndk/android-ndk-r9d-windows-x86_64.zip
Android SDK (command line tools, at the bottom of the page) - https://developer.android.com/studio/index.html
Apache Ant (latest binary distribution zip) - http://ant.apache.org/bindownload.cgi
Java DK (top left, whatever os/bit system you're running on) - http://www.oracle.com/technetwork/java/javase/downloads/index.html


  Setup/First Run
------------------
1. Extract the ndk, sdk and ant to a folder and give them small names (if you like your hands)
2. Go ahead and install the JDK
3. Go into android-sdk -> tools -> android.bat
4. Install these items 

	Tools
		Android SDK Platform-tools
		Android SDK Build-Tools Rev (latest)
	Android x.x.x (API xx) xx is the version number in androidmanifest.xml and project.properties                      
		SDK Platform
		ARM EABI v7a System Image
		Google APIs ARM EABI v7a System Image (if you want intel support do the same thing as the ones above, but for intel)
		Google APIs (7.0 and below)
		Sources for Android SDK
	Extras
		Android Support Repository
		Google USB driver
		
5. While they download and install go to android-ndk -> build -> core -> setup-toolchain.mk and comment (#) out
line 37 (TARGET_TOOLCHAIN_LIST := $(filter-out %4.7 %4.8,$(TARGET_TOOLCHAIN_LIST)))
6. Right click setup(64).bat and click Run as administer to setup everything before you start compiling (note: use setup64.bat if you use 64bit)
7. Enter in all the directories carefully
7.5 If you think you messed up anything just run fixpath.bat
8. In the command prompt that showed up type in the directory to the root of the mod
9. Let the new command prompt run and exit out of it when it finishes
10. Press enter on the original command prompt and "repeat" step 9
11. Press D on the original command prompt and enjoy your cool mod
 
 
 Compiling a Mod
-----------------
1. Run blac.bat
2. In the command prompt that showed up type in the directory to the root of the mod
3. Let the new command prompt run and exit out of it when it finishes
4. Press enter on the original command prompt and "repeat" step 9
5. Press D on the original command prompt and enjoy your cool mod


 Uninstalling
--------------
1. Run fixpath.bat
2. Delete folder


DM me any issues on slack