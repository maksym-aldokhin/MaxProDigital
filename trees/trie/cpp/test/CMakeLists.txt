if(NOT ENABLE_TESTING)
	return()
endif()

add_executable(tree_trie_test
	TrieTree_test.cpp
	TrieTreePriority_test.cpp
)

target_link_libraries(tree_trie_test
	PRIVATE
		tree_trie
		gtest_main
)

gtest_discover_tests(tree_trie_test
	PROPERTIES
		LABELS "tree_trie"
	DISCOVERY_TIMEOUT
		240
)
