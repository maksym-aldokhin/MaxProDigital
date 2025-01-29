cmake_minimum_required(VERSION 3.13)

project(MaxProDigitalExamples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

set(ENABLE_TESTING OFF CACHE BOOL "Enable testing")

if(ENABLE_TESTING)
	enable_testing()

	include(FetchContent)
	FetchContent_Declare(gtest
		QUIET
		URL https://github.com/google/googletest/releases/download/v1.15.2/googletest-1.15.2.tar.gz
		DOWNLOAD_EXTRACT_TIMESTAMP TRUE
	)

	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)

	FetchContent_MakeAvailable(gtest)

	include(GoogleTest)
endif()

add_subdirectory(search/cpp/src)
add_subdirectory(search/cpp/test)

add_subdirectory(queue/cpp/queue)
add_subdirectory(queue/cpp/test)

add_subdirectory(stack/cpp/src)
add_subdirectory(stack/cpp/test)

add_subdirectory(trees/trie/cpp/src)
add_subdirectory(trees/trie/cpp/test)
