set(sources
	Sort.cpp
)

set(headers
	Sort.h
)

add_library(Sort)

target_sources(Sort
	PRIVATE
		${sources}
	PUBLIC
		${headers}
)

target_include_directories(Sort
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)
