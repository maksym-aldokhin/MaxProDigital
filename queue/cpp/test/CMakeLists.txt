if(NOT ENABLE_TESTING)
	return()
endif()

add_executable(queue_test
	queue_test.cpp
)

target_link_libraries(queue_test
	PRIVATE
		queue
		gtest_main
)

gtest_discover_tests(queue_test
	PROPERTIES
		LABELS "unit"
	DISCOVERY_TIMEOUT
		240
)
