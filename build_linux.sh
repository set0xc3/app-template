#!/bin/sh

ROOT_DIR=$PWD
BUILD_PATH=$PWD/build
BUILD_TYPE=Debug

if [ "$1" = "Debug" ]   
then
    BUILD_TYPE=Debug
elif [ "$1" = Release ] 
then
    BUILD_TYPE=Release
fi

BIN_PATH=$BUILD_PATH/$BUILD_TYPE

echo ==============================================================================
echo "BUILD_TYPE: $BUILD_TYPE"
echo "ROOT_DIR:   $ROOT_DIR"
echo "BUILD_PATH: $BUILD_PATH"
echo "BIN_PATH:   $BIN_PATH"
echo ==============================================================================

#rm -r "$BUILD_PATH"

mkdir -p "$BUILD_PATH"
pushd "$BUILD_PATH/"  > /dev/null
    cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_INSTALL_PREFIX=$BIN_PATH -DCMAKE_BUILD_TYPE=$BUILD_TYPE -S$ROOT_DIR -B$BUILD_PATH -G Ninja
    cmake --build . --config $BUILD_TYPE
popd  > /dev/null
