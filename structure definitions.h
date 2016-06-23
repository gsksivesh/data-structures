typedef struct trie_structure{
	struct trie_structure *childs[26];
	int isLeaf;
}Trie;