set(sources
	Search.cpp
)

set(headers
	Search.h
)

add_library(Search)

target_sources(Search
	PRIVATE
		${sources}
	PUBLIC
		${headers}
)

target_include_directories(Search
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)
