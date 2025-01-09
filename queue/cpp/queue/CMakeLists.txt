set(sources
	queue.cpp
)

set(headers
	queue.h
)

add_library(queue)

target_sources(queue
	PRIVATE
		${sources}
	PUBLIC
		${headers}
)

target_include_directories(queue
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)
