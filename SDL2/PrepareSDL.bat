SET USER_LIB_PATH=""
SET USER_APP_PATH=
SET DEBUG_APP_PATH=libs_debug
SET RELEASE_APP_PATH=libs_release

mkdir PreparedData
xcopy /y /s .\ARM .\PreparedData\ARM\
xcopy /y /s .\ARM64 .\PreparedData\ARM64\
xcopy /y /s .\x86 .\PreparedData\x86\
xcopy /y /s .\x64 .\PreparedData\x64\
cd PreparedData
del /s *.o
del /s *.log

cd .\ARM\Debug
xcopy /y *.so "%USER_APP_PATH%\%DEBUG_APP_PATH%\armeabi-v7a\."
rmdir SDL2.tlog /s /q
cd ..
cd Release
xcopy /y *.so "%USER_APP_PATH%\%RELEASE_APP_PATH%\armeabi-v7a\."
rmdir SDL2.tlog /s /q
cd ../..

cd .\ARM64\Debug
xcopy /y *.so "%USER_APP_PATH%\%DEBUG_APP_PATH%\arm64-v8a\."
rmdir SDL2.tlog /s /q
cd ..
cd Release
xcopy /y *.so "%USER_APP_PATH%\%RELEASE_APP_PATH%\arm64-v8a\."
rmdir SDL2.tlog /s /q
cd ../..

cd .\x86\Debug
xcopy /y *.so "%USER_APP_PATH%\%DEBUG_APP_PATH%\x86\."
rmdir SDL2.tlog /s /q
cd ..
cd Release
xcopy /y *.so "%USER_APP_PATH%\%RELEASE_APP_PATH%\x86\."
rmdir SDL2.tlog /s /q
cd ../..

cd x64/Debug
xcopy /y *.so "%USER_APP_PATH%\%DEBUG_APP_PATH%\x64\."
rmdir SDL2.tlog /s /q
cd ..
cd Release
xcopy /y *.so "%USER_APP_PATH%\%RELEASE_APP_PATH%\x64\."
rmdir SDL2.tlog /s /q
cd ../..

xcopy /y /s *.* %USER_LIB_PATH%

cd ..
