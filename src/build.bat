@REM Author: NULL_703
@REM Created time: 2021.10.10 18:12
@REM Last change time: 2021.10.17 16:04

@echo off
:try
set /p opt="Please input Mode(1:build 2:clean):"
if "%opt%"=="1" (
    make -f Winmakefile
    pause
    goto end
)
else (
    if "%opt%"=="2" (
        make -f Winmakefile clean
        pause
        goto end
    )
)
else (
    echo Error: No this option!
    goto try
)
:end
echo Finish.