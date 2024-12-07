cmake_minimum_required(VERSION 3.29)
set(TARGETNAME "CodeGen")
project(${TARGETNAME} VERSION 0.1)

set(SOURCES
 src/Code.cpp
 src/CodeTree.cpp
 src/direct.cpp
 src/dllmain.cpp
 src/ElementData.cpp
 src/FuncArgs.cpp
 src/IntFunc.cpp
 src/Objects.cpp
 src/Parser.cpp
 src/Runner.cpp
 src/share.cpp
)

add_library(${TARGETNAME} SHARED ${SOURCES})

set_property(TARGET ${TARGETNAME} PROPERTY CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-fPIC" )
set(CMAKE_SHARED_LINKER_FLAGS "-s" )

if (WIN32)
	add_definitions( -DBUILDING_DLL )

	# Removing the "lib" prefix during compilation in MSYS2 on Windows
	set_target_properties(${TARGETNAME} PROPERTIES PREFIX "")
	target_link_libraries( ${TARGETNAME} PRIVATE -static-libgcc -static-libstdc++ -static )
endif ()

if (UNIX AND NOT APPLE)
	target_link_libraries( ${TARGETNAME} PRIVATE -shared )
endif ()
