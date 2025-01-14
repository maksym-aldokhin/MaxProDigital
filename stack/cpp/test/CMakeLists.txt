if(NOT ENABLE_TESTING)
	return()
endif()

add_executable(stack_test
	StackList_test.cpp
	StackFixSize_test.cpp
	StackVectorUnlimited_test.cpp
)

target_link_libraries(stack_test
	PRIVATE
		stack
		gtest_main
)

gtest_discover_tests(stack_test
	PROPERTIES
		LABELS "stack"
	DISCOVERY_TIMEOUT
		240
)
