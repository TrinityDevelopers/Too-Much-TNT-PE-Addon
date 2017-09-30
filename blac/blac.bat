@echo off

::Ask what directory is the mod located
set /p dir=<modpath.txt

::ndk-build
echo Building the library
START cmd.exe /k "cd %dir% & ndk-build & PAUSE & exit"

echo Press a button to build the apk
TIMEOUT /T -1

echo Building the apk
START cmd.exe /k "cd %dir% & ant debug & exit"

echo Apk is located in the root of the mod's directory
xcopy /s "%dir%\bin\*debug.apk" "%dir%\apk"

echo Running apk on attached device
START cmd.exe /k "cd %dir%\apk & adb install -r toomuchtnt-debug.apk & PAUSE & exit"

PAUSE
exit