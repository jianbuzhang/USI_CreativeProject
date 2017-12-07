@echo off
cd /d %~dp0
if not exist %~dp0Logfile\ md %~dp0Logfile\ 

:Begin
cls
set /p SN=Pls input the SN:
:start
cls
adb devices | find /v /i "List" | find /i "device"
if errorlevel 1 echo wait for device... && adb wait-for-device && goto start

adb root
if errorlevel 1 goto fail
set SSN=
for /f "" %%i in ('adb devices ^| find /v /i "List" ^| find /i "device"') do set SSN=%%i
if not defined SSN goto fail
echo %0 test start ... --%date% %time% >> %~dp0Logfile\%SN%.log
adb root
adb reboot-bootloader

if errorlevel 1 goto fail
echo Pls VolumeDownd 2 times-- select Factory Reset--Press PWR to confirm
echo wait DUT factory reset...
echo wait DUT factory reset... >> %~dp0Logfile\%SN%.log
ping 127.0.0.1 -n 50 >nul
:waitreboot
adb devices | find /v /i "List" | find /i "device"
if errorlevel 1 echo wait for device... && adb wait-for-device && goto waitreboot
goto end

:fail
echo fail,pls check
pause>nul
exit

:end
cls
echo DUT:%SN% is successfully FastbootFactoryReset
echo DUT:%SN% is successfully FastbootFactoryReset --%date% %time% >> %~dp0Logfile\%SN%.log
echo Press any key to retest next UUT
pause>nul
goto Begin