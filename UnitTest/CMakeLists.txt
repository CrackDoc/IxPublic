# CMakeList.txt: CMakeProject 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

#-----------------TODO 自定义编译选项
# SET(CMAKE_CXX_FLAGS “-std=c++11 -O2 -g”)

string(REGEX REPLACE "/$" "" CURRENT_FOLDER_ABSOLUTE ${CMAKE_CURRENT_SOURCE_DIR})

string(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CURRENT_FOLDER_ABSOLUTE})

string(REGEX REPLACE "(.*)/${CURRENT_FOLDER}$" "\\1" MODULE_FOLDER_ABSOLUTE ${CURRENT_FOLDER_ABSOLUTE})

string(REGEX REPLACE ".*/(.*)" "\\1" MODULE_FOLDER ${MODULE_FOLDER_ABSOLUTE})

#get_filename_component(MODULE_FOLDER_ABSOLUTE ${CURRENT_FOLDER_ABSOLUTE} DIRECTORY)
#get_filename_component(MODULE_FOLDER ${CURRENT_FOLDER_ABSOLUTE} NAME)

#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)

#find_package(IDE)

#if(IDE_FOUND)
#	SET(CMAKE_INSTALL_PREFIX ${IDE_INCLUDE_DIR}/${MODULE_FOLDER}) 
#else()
#endif(IDE_FOUND)

#-----------------TODO 添加模块变量
SET(_INC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../${CURRENT_FOLDER}/include)
SET(_SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../${CURRENT_FOLDER}/src)

#当前工程的模块
SET(MODULE_PATH ${CMAKE_INSTALL_PREFIX}/${MODULE_FOLDER})

#添加其他工程模块
#SET(OHTER_PATH ${IDE_PATH}/${OTHER_INCLUDE_DIR})

#MESSAGE(STATUS ${MODULE_FOLDER_ABSOLUTE})
#MESSAGE(STATUS ${MODULE_FOLDER})
MESSAGE(STATUS ${MODULE_PATH})

# 添加执行EXE目录
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/../${CURRENT_FOLDER}/include _INC_EXPATH)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/../${CURRENT_FOLDER}/src _SRC_EXPATH)

#-----------------TODO添加头文件的搜索目录
include_directories(${_INC_PATH})
include_directories(${_SRC_PATH})
include_directories(${MODULE_PATH}/include)

#-----------------TODO 添加lib文件的搜索目录
link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../${CURRENT_FOLDER}/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
link_directories(${MODULE_PATH}/lib)

#-----------------TODO EXE编译连接
add_executable (${CURRENT_FOLDER} ${_INC_EXPATH} ${_SRC_EXPATH})

#-----------------TODO 创建工程内的库
#-----------------STATIC表示创建静态库，目标文件为 libmylib.a，如果是 SHARED， 则为创建动态库.
#add_library(${CURRENT_FOLDER} SHARED ${_INC_EXPATH} ${_SRC_EXPATH})

#-----------------TODO 连接lib 文件
#MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")
#IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
#	MESSAGE(STATUS "current platform: Linux ")
#ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
#	MESSAGE(STATUS "current platform: Windows")
#ELSEIF (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
#	MESSAGE(STATUS "current platform: FreeBSD")
#ELSE ()
#	MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
#ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")
 
#MESSAGE(STSTUS "###################################")

IF (WIN32)
	target_link_libraries(${CURRENT_FOLDER} ${MODULE_FOLDER}.lib)
ELSEIF (Linux)
	target_link_libraries(${CURRENT_FOLDER} ${MODULE_FOLDER}.so)
ELSEIF (UNIX)
	MESSAGE(STATUS "Now is UNIX-like OS's.")
ENDIF ()

#-----------------TODO 执行外部命令
#set(THRIFT_FILE ${CMAKE_CURRENT_SOURCE_DIR}/mythrift.thrift)
#exec_program("thrift --gen cpp -o ${CMAKE_CURRENT_SOURCE_DIR} ${THRIFT_FILE}")

#-----------------TODO: 如有需要，请添加测试并安装目标。
