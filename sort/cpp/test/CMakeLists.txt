if(NOT ENABLE_TESTING)
	return()
endif()

add_executable(Sort_test
	BubbleSort_test.cpp
)

target_link_libraries(Sort_test
	PRIVATE
		Sort
		gtest_main
)

gtest_discover_tests(Sort_test
	PROPERTIES
		LABELS "sort"
	DISCOVERY_TIMEOUT
		240
)
