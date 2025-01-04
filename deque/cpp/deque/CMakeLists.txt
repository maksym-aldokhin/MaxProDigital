set(sources
	deque.cpp
)

set(headers
	deque.h
)

add_library(deque)

target_sources(deque
	PRIVATE
		${sources}
	PUBLIC
		${headers}
	)

target_include_directories(deque
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
	)
