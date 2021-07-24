cmake_minimum_required(VERSION 3.4.1)

# 加载头文件
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/JavaScriptCore)

# 添加nativeLog
find_library(
    log-lib
    log
)


#加载 afc_bridge
add_library(afc SHARED
             ./bridge.cpp )
#添加JavaScriptCore so
add_library(JavaScriptCore SHARED IMPORTED)

#设定jsc.so 目标文件位置
set_target_properties(JavaScriptCore PROPERTIES IMPORTED_LOCATION
            "${CMAKE_CURRENT_SOURCE_DIR}/../lib/android/${ANDROID_ABI}/libjsc.so")
#添加 cpp_shard
add_library(cpp_shared SHARED IMPORTED)

#设定libc++_shared.so 目标文件位置
set_target_properties(cpp_shared PROPERTIES IMPORTED_LOCATION
            "${CMAKE_CURRENT_SOURCE_DIR}/../lib/android/${ANDROID_ABI}/libc++_shared.so")

#添加链接库
target_link_libraries(afc cpp_shared JavaScriptCore ${log-lib})