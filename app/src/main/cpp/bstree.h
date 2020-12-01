#ifndef _BSTREE_H
#define _BSTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include "trietree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BSTNode BSTNode;

struct BSTNode {
    char data;
    struct BSTNode *pLchild;
    struct BSTNode *pRchild;
    struct TrieNode *pNext;
};

void CreateBSTree(struct BSTNode **ppBst);
void InsertBSTree(struct BSTNode *pBST, char value);
struct BSTNode *SearchBSTree(struct BSTNode *pBST, char key);

#ifdef __cplusplus
}
#endif

#endif // _BSTREE_H