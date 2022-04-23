# CMakeList.txt: newCode_zuochengyun 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("Algorithm")
# 设置g++编译器中标准
set(CMAKE_CXX_STANDARD 14)

# 将源代码添加到此项目的可执行文件。
add_executable (BubbleSort "BubbleSort.cpp" "public.h"  "HeapSort.cpp")
add_executable (SelectSort  "SelectSort.cpp"  "HeapSort.cpp")
add_executable(InsertSort "InsertSort.cpp" "public.h"  "HeapSort.cpp")
add_executable(FindAppearOddTimeNumber "FindAppearOddTimeNumber.cpp" "public.h"  "HeapSort.cpp")
add_executable(FindAppearOddTimeTwoNumber  "public.h" "FindAppearOddTimeTwoNumber.cpp" "HeapSort.cpp")

add_executable(findMaxValue  "public.h" "findMaxValue.cpp" "HeapSort.cpp")

add_executable(MergeSortNonRecursion  "public.h" "MergeSortNonRecursion.cpp" )

add_executable(HeapSort  "public.h"  "HeapSort.cpp")
