@echo off

::Presets
set fakepath=%Path%
set /p boolpath=<bool.txt

::Save the path just in case
@echo %fakepath% > path.txt

if %boolpath% EQU 0 goto option1

:option1
@echo %fakepath% > pathbackup.txt 

@echo 1 > bool.txt

::Ask where they put the Android NDK
set /p NDK="Location of Android NDK: "

::Ask where they put the Android SDK
set /p SDK="Location of Android SDK: "

::Ask where they put the Apache Ant folder
set /p ANT="Location of Apache Ant: "

::Ask where did they install Java
set /p JAVA="Location of JavaDK: "

echo Setting up the necessary Windows Environment Variable
setx ANDROID_NDK "%NDK%" /m
setx ANDROID_SDK "%SDK%" /m
setx ANDROID_HOME "%SDK%" /m
setx ANDROID_SWT "%ANDROID_SDK%\tools\lib\x86_64" /m
setx ANT_HOME "%ANT%" /m
setx JAVA_HOME "%JAVA%" /m

cd %~dp0Pathed_1.0\bin
pathed -a "%ANT%\bin;%SDK%\tools;%NDK%"

echo Install finished, run blac.bat to start compiling

PAUSE