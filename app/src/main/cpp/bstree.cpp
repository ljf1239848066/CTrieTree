#include "bstree.h"

void CreateBSTree(struct BSTNode **ppBst) {
    *ppBst = (struct BSTNode *)malloc(sizeof(struct BSTNode));
    (*ppBst)->data = 0;
    (*ppBst)->pLchild = NULL;
    (*ppBst)->pRchild = NULL;
    (*ppBst)->pNext = NULL;
}

struct BSTNode *InsertBSTree(struct BSTNode **pRoot, struct BSTNode *node) {
    if(*pRoot == NULL) {
        *pRoot = node;
        return node;
    }
    struct BSTNode *pCur = *pRoot;
    while (true) {
        if (node->data < pCur->data) {
            if(pCur->pLchild) {
                pCur = pCur->pLchild;
            } else {
                pCur->pLchild = node;
                break;
            }
        } else {
            if(pCur->pRchild) {
                pCur = pCur->pRchild;
            } else {
                pCur->pRchild = node;
                break;
            }
        }
    }
    return node;
}

struct BSTNode *SearchBSTree(struct BSTNode *pRoot, char key) {
    struct BSTNode *pTmp = pRoot;
    while (NULL != pTmp && key != pTmp->data) {
        if (key < pTmp->data) {
            pTmp = pTmp->pLchild;
        } else {
            pTmp = pTmp->pRchild;
        }
    }
    return pTmp;
}