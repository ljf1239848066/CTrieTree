#ifndef _BSTREE_H
#define _BSTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include "trietree.h"
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct BSTNode BSTNode;

struct BSTNode {
    jchar data;
    struct BSTNode *pLchild;
    struct BSTNode *pRchild;
    struct TrieNode *pNext;
};

void CreateBSTree(struct BSTNode **ppBst);
struct BSTNode *InsertBSTree(struct BSTNode **pBST, struct BSTNode *node);
struct BSTNode *SearchBSTree(struct BSTNode *pBST, jchar key);

#ifdef __cplusplus
}
#endif

#endif // _BSTREE_H