#!/bin/sh

rm -rf build/
rm compile_commands.json

conan install . --output-folder build --build=missing -s build_type=Debug -pr:b=default
cmake -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake . -GNinja
cmake --build build

ln -s build/compile_commands.json compile_commands.json
