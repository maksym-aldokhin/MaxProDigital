set(sources
	StackList.cpp
	StackFixSize.cpp
	StackVectorUnlimited.cpp
)

set(headers
	StackList.h
	StackFixSize.h
	StackVectorUnlimited.h
)

add_library(stack)

target_sources(stack
	PRIVATE
		${sources}
	PUBLIC
		${headers}
)

target_include_directories(stack
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)
