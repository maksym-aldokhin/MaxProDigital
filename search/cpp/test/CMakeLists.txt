if(NOT ENABLE_TESTING)
	return()
endif()

add_executable(Search_test
	LinerSearch_test.cpp
)

target_link_libraries(Search_test
	PRIVATE
		Search
		gtest_main
)

gtest_discover_tests(Search_test
	PROPERTIES
		LABELS "search"
	DISCOVERY_TIMEOUT
		240
)
