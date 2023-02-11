@echo off

set ROOT_DIR=%CD%
set BUILD_PATH=%CD%\build
set BUILD_TYPE=Debug

if "%1%"=="Debug"   set BUILD_TYPE=Debug
if "%1%"=="Release" set BUILD_TYPE=Release

set BIN_PATH=%BUILD_PATH%\%BUILD_TYPE%

echo "=============================="
echo "-- ROOT_DIR:      %ROOT_DIR%"
echo "-- BUILD_TYPE:    %BUILD_TYPE%"
echo "-- BUILD_PATH:    %BUILD_PATH%"
echo "-- BIN_PATH:      %BIN_PATH%"
echo "=============================="

:rmdir /q /s %BUILD_PATH%

mkdir %BUILD_PATH%
pushd %BUILD_PATH%
    cmake .. -DCMAKE_INSTALL_PREFIX=%BIN_PATH% -DCMAKE_BUILD_TYPE=%BUILD_TYPE% -S%ROOT_DIR% -B%BUILD_PATH%
    cmake --build .
    cmake --install . --config %BUILD_TYPE%
popd
