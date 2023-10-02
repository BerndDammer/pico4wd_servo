call ../../../SetEnv.bat
rem set
rem pause

set CMAKE_MAKE_PROGRAM=make


cd ..

call cmake -S src -B . -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug
pause


