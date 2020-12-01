#ifndef _TRIETREE_H
#define _TRIETREE_H

#include "bstree.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct TrieNode TrieNode;

struct TrieNode {
    int length;
    char *category;
    char *riskLevel;
    BSTNode *next;
};

void buildDictionary(TrieNode **root);
TrieNode *createBranch(char* name, char* definition);
void addDictionary(TrieNode **root, char *name, char *definition);
char *searchDictionary(TrieNode **root, char *name);

#ifdef __cplusplus
}
#endif

#endif // _TRIETREE_H