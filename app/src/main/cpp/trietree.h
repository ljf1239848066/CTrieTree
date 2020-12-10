#ifndef _TRIETREE_H
#define _TRIETREE_H

#include "bstree.h"
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct TrieNode TrieNode;

struct TrieNode {
    int length;
    char *category;
    char *riskLevel;
    struct BSTNode *next;
};

struct SearchResult {
    int start;
    int end;
    const char *category;
    const char *riskLevel;
};

struct ResultList {
    SearchResult *result;
    ResultList *next;
};

void makeNode(TrieNode **root);
TrieNode *createNode();
void makeResult(SearchResult **result);
void releaseResult(SearchResult **result);
void addResult(ResultList **resultList, SearchResult *result);
void addDictionary(JNIEnv *env, TrieNode **root, const jchar *name, int len, char *definition, char *riskLevel);
void addDictionary1(JNIEnv *env, TrieNode **root, const char *name, char *definition, char *riskLevel);
ResultList *searchDictionary(JNIEnv *env, TrieNode **root, const jchar *wordSearch, int jlen);
ResultList *searchDictionary1(JNIEnv *env, TrieNode **root, const char *wordSearch);

void jcharTochar(JNIEnv *env, const jchar *src, int jlen, char **out);
void charToJchar(JNIEnv *env, const char *src, jchar **out, int *jlen);

#ifdef __cplusplus
}
#endif

#endif // _TRIETREE_H