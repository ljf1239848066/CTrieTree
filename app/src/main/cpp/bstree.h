#ifndef _BSTREE_H
#define _BSTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

struct BSTNode
{
    char data;
    struct BSTNode *pLchild;
    struct BSTNode *pRchild;
};

void InsertBSTree(struct BSTNode *pBST, int InsertVal);
struct BSTNode *SearchBSTree(struct BSTNode *pBST, char key);

#ifdef __cplusplus
}
#endif

#endif // _BSTREE_H