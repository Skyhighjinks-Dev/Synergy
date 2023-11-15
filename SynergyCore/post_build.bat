@echo off

set "logFile=D:\Synergy\SynergyCore\myLog.log"

echo Logging output to %logFile% 
(
echo %1
echo %2
echo %3

echo %1SynergyCore.dll
echo %1SynergyCore.lib

copy "%1SynergyCore.dll" "%2"
copy "%1SynergyCore.lib" "%2"
) >> %logFile%