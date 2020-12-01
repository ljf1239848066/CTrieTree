#include "bstree.h"

void CreateBSTree(struct BSTNode **ppBst) {
    *ppBst = (struct BSTNode *)malloc(sizeof(struct BSTNode));
}

void InsertBSTree(struct BSTNode *pRoot, char value) {
    struct BSTNode *pNew = (struct BSTNode *) malloc(sizeof(struct BSTNode));
    if (NULL == pNew) {
        return;
    }
    pNew->data = value;
    pNew->pLchild = pNew->pRchild = NULL;
    struct BSTNode *pCur = pRoot;
    while (true) {
        if (value < pCur->data) {
            if(pCur->pLchild) {
                pCur = pCur->pLchild;
            } else {
                pCur->pLchild = pNew;
                break;
            }
        } else {
            if(pCur->pRchild) {
                pCur = pCur->pRchild;
            } else {
                pCur->pRchild = pNew;
                break;
            }
        }
    }
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