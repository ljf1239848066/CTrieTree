#include "trietree.h"
#include "utils/gtlog.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//build dictionary
void makeNode(TrieNode **root) {
    *root = createNode();
}

//create node
TrieNode *createNode() {
    //start create the trie and all value is NULL
    TrieNode *branch = (TrieNode *) malloc(sizeof(TrieNode)); //let branch hv same size as trie
    branch->length = 0;
    branch->category = NULL;
    branch->riskLevel = NULL;
    branch->next = NULL; //next is for sub tree
    return branch;
}

//adding word into dictionary
void addDictionary(TrieNode **root, char *name, char *category, char *riskLevel) { // add word
    if (NULL == name) {
        return;
    }
    TrieNode *current = *root;
    int len = strlen(name);
    for (int i = 0; i < len; i++) {
        char ch = name[i];
        BSTNode *node = current->next ? nullptr : SearchBSTree(current->next, ch);
        if (node) {
            current = node->pNext;
        } else {
            TrieNode *tmpTNode = NULL;
            makeNode(&tmpTNode);

            BSTNode *newNode = NULL;
            CreateBSTree(&newNode);
            newNode->data = ch;

//            if(!current->next) {
//                current->next =
//            }
            node = InsertBSTree(&(current->next), newNode);
            node->pNext = tmpTNode;
            current = tmpTNode;
        }
    }
    current->length = len;
    current->category = category;
    current->riskLevel = riskLevel;
    return;
}

void substring(char *src, int start, int end, char **out) {
    int len = end - start;
    *out = (char *) malloc(len + 1);
    memset(*out, 0, len + 1);
    memcpy(*out, src + start, len);
}

//search dictionary
char *searchDictionary(TrieNode **root, char *wordSearch) {
    TrieNode *tmp;
    char ch;
    int len = strlen(wordSearch);
    int i = 0;
    int end = 0;
    while (i < len) {
        tmp = *root;
        char *sub = wordSearch + i;
        for (int j = 0; j < len - i; j++) {
            ch = sub[j];
            BSTNode *node = SearchBSTree(tmp->next, ch);
            if (node) {
                tmp = node->pNext;
                if (tmp->length > 0) {
                    end = i + tmp->length;
                    char *out = nullptr;
                    substring(wordSearch, i, end, &out);
                    LOGI("item start:%d end:%d keyword:%s", i, end, out);
                    free(out);
                    out = nullptr;
                }
            } else {
                break;
            }
        }
        i = ((i + 1) > end ? (i + 1) : end);
    }
    return nullptr;
}