set(sources
	TrieTree.cpp
	TrieTreePriority.cpp
)

set(headers
	TrieTree.h
	TrieTreePriority.h
)

add_library(tree_trie)

target_sources(tree_trie
	PRIVATE
		${sources}
	PUBLIC
		${headers}
)

target_include_directories(tree_trie
	PUBLIC
		${CMAKE_CURRENT_LIST_DIR}
)
