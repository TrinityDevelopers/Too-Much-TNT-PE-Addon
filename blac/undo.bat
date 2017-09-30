@echo off

::Presets
set /p pathtmp=<path.txt
@echo 0 > bool.txt

echo Press a button to fix the Path Environment Variable or click the X button to stop the operation
TIMEOUT /T -1

setx Path "%pathtmp%" /m

PAUSE