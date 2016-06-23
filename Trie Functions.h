#include "incuding headers.h"
#include "structure definitions.h"
#include "helper functions.h"

Trie *new_node()
{
	Trie *temp;
	temp = (Trie *)malloc(sizeof(Trie));
	memset(temp, NULL, sizeof(Trie));
	return temp;
}


void insert(Trie *root, char *string)
{
	Trie *temp;
	temp = root;
	for (int i = 0; string[i] != '\0'; i++)
	{
		int index = char_to_index(string[i]);
		if (temp->childs[index] == NULL)
		{
			temp->childs[index] = new_node();
		}
		temp = temp->childs[index];
	}
	temp->isLeaf = 1;
}


int search_trie(Trie *root, char *string)
{
	for (int i = 0; string[i] != '\0'; i++)
	{
		int index = char_to_index(string[i]);
		if (root->childs[index] == NULL)
		{
			return 0;
		}
		root = root->childs[index];
	}
	if (root->isLeaf != 1)
	{
		return 0;
	}
	return 1;
}