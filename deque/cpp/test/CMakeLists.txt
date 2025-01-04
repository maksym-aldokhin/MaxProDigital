if(NOT ENABLE_TESTING)
	return()
endif()

add_executable(deque_test
	deque_test.cpp
)

target_link_libraries(deque_test
	PRIVATE
		deque
		gtest_main
)

gtest_discover_tests(deque_test
	PROPERTIES
		LABELS "unit"
	DISCOVERY_TIMEOUT
		240
)
