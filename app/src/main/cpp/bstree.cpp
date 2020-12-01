
#include "bstree.h"

void InsertBSTree(struct BSTNode *pRoot, char value) {
    struct BSTNode *pRootBak = pRoot;//记录根节点地址
    struct BSTNode *pNew = (struct BSTNode *) malloc(sizeof(struct BSTNode));
    if (NULL == pNew) {
        return;
    }
    pNew->data = value;
    pNew->pLchild = pNew->pRchild = NULL;
    struct BSTNode *pTmp = NULL;
    struct BSTNode *pCur = pRoot;
    while (NULL != pCur) {
        pTmp = pCur;
        if (pNew->data < pCur->data) {
            pCur = pCur->pLchild;
        } else {
            pCur = pCur->pRchild;
        }
    }
    if (NULL == pTmp) {//当树为空时，将插入节点的地址赋给根节点
        *pRootBak = *pNew;
    } else if (pNew->data <= pTmp->data) {
        pTmp->pLchild = pNew;
    } else {
        pTmp->pRchild = pNew;
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