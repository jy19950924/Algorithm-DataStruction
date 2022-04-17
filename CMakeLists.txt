# CMakeList.txt: newCode_zuochengyun 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("Algorithm")

# 将源代码添加到此项目的可执行文件。
add_executable (BubbleSort "BubbleSort.cpp" "public.h" )

add_executable (SelectSort  "SelectSort.cpp" )

add_executable(InsertSort "InsertSort.cpp" "public.h" )
add_executable(FindAppearOddTimeNumber "FindAppearOddTimeNumber.cpp" "public.h" )
add_executable(FindAppearOddTimeTwoNumber  "public.h" "FindAppearOddTimeTwoNumber.cpp")

