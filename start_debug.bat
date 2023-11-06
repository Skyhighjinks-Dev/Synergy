@echo off

echo Starting the first application...
start "Server Application" "%CD%\bin\Debug\SynergyServer\SynergyServer.exe"
timeout /t 1 /nobreak > nul

echo Starting the second application...
start "Client Application" "%CD%\bin\Debug\SynergyClient\SynergyClient.exe 127.0.0.1"