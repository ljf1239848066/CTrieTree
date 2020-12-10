#include "trietree.h"
#include "utils/gtlog.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


void substring(const char *src, int start, int end, char **out) {
    int len = end - start;
    *out = (char *) malloc(len + 1);
    memset(*out, 0, len + 1);
    memcpy(*out, src + start, len);
}

void substring(const jchar *src, int start, int end, jchar **out) {
    int len = (end - start) * sizeof(jchar);
    *out = (jchar *) malloc(len);
    memcpy(*out, src + start, len);
}

void jcharTochar(JNIEnv *env, const jchar *src, int jlen, char **out) {
    jstring str = env->NewString(src, jlen);
    const char *chs = env->GetStringUTFChars(str, NULL);
    int len = strlen(chs);
    *out = (char *) malloc(len + 1);
    strcpy(*out, chs);
    env->ReleaseStringUTFChars(str, chs);
    env->DeleteLocalRef(str);
}

void charToJchar(JNIEnv *env, const char *src, jchar **out, int *jlen) {
    int len = strlen(src);
    jclass strClass = env->FindClass("com/lxzh123/ctrietree/Native");
    jmethodID ctorID = env->GetStaticMethodID(strClass, "newString", "([B)Ljava/lang/String;");
    jbyteArray bytes = env->NewByteArray(len);
    env->SetByteArrayRegion(bytes, 0, len, (jbyte *) src);
    jstring jstr = (jstring) env->CallStaticObjectMethod(strClass, ctorID, bytes);

    jboolean jbIsCopy = JNI_TRUE;
    const jchar *jchs = env->GetStringChars(jstr, &jbIsCopy);
    *jlen = env->GetStringLength(jstr);
    len = (*jlen) * 2;
    *out = (jchar *) malloc(len);
    memcpy(*out, jchs, len);

    env->ReleaseStringChars(jstr, jchs);
    env->DeleteLocalRef(jstr);
    env->ReleaseByteArrayElements(bytes, (jbyte *) src, JNI_COMMIT);
    env->DeleteLocalRef(strClass);
}

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

void makeResult(SearchResult **result) {
    *result = (SearchResult *) malloc(sizeof(SearchResult));
    (*result)->start = 0;
    (*result)->end = 0;
    (*result)->category = NULL;
    (*result)->riskLevel = NULL;
}

void makeResultList(ResultList **result) {
    *result = (ResultList *) malloc(sizeof(ResultList));
    (*result)->result = NULL;
    (*result)->next = NULL;
}

void releaseResult(SearchResult **result) {
    if (result == NULL || *result == NULL) {
        return;
    }
    (*result)->start = 0;
    (*result)->end = 0;
    (*result)->category = NULL;
    (*result)->riskLevel = NULL;
    *result = NULL;
}

void addResult(ResultList **resultList, SearchResult *result) {
    if (*resultList == NULL) {
        makeResultList(resultList);
    }
    ResultList *pre = *resultList;
    ResultList *tmp = *resultList;
    while (tmp != NULL && tmp->result != NULL) {
        pre = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) {
        makeResultList(&tmp);
        pre->next = tmp;
    }
    tmp->result = result;
}

//adding word into dictionary
void addDictionary(JNIEnv *env, TrieNode **root, const jchar *name, int len, char *category,
                   char *riskLevel) { // add word
    if (NULL == name) {
        return;
    }
    TrieNode *current = *root;
    for (int i = 0; i < len; i++) {
        jchar ch = name[i];
        BSTNode *node = current->next ? nullptr : SearchBSTree(current->next, ch);
        if (node) {
            current = node->pNext;
        } else {
            TrieNode *tmpTNode = NULL;
            makeNode(&tmpTNode);

            BSTNode *newNode = NULL;
            CreateBSTree(&newNode);
            newNode->data = ch;

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

void
addDictionary1(JNIEnv *env, TrieNode **root, const char *name, char *category, char *riskLevel) {
    if (NULL == name) {
        return;
    }
    jchar *jnames = NULL;
    int len = 0;
    charToJchar(env, name, &jnames, &len);
    addDictionary(env, root, jnames, len, category, riskLevel);
    free(jnames);
}

ResultList *searchDictionary(JNIEnv *env, TrieNode **root, const jchar *wordSearch, int jlen) {
    TrieNode *tmp;
    jchar ch;
    int i = 0;
    int end = 0;
    ResultList *resultList = NULL;
    while (i < jlen) {
        tmp = *root;
        jchar *sub = (jchar *) (wordSearch + i);
        for (int j = 0; j < jlen - i; j++) {
            ch = sub[j];
            BSTNode *node = SearchBSTree(tmp->next, ch);
            if (node) {
                tmp = node->pNext;
                if (tmp->length > 0) {
                    end = i + tmp->length;
                    jchar *out = nullptr;
                    substring(wordSearch, i, end, &out);
                    LOGI("item start:%d end:%d keyword:%s", i, end, out);
                    SearchResult *result = NULL;
                    makeResult(&result);
                    result->start = i;
                    result->end = end;
                    result->category = tmp->category;
                    result->riskLevel = tmp->riskLevel;
//                    if (resultList == NULL) {
//                        makeResultList(&resultList);
//                    }
                    addResult(&resultList, result);

                    free(out);
                    out = nullptr;
                }
            } else {
                break;
            }
        }
        i = ((i + 1) > end ? (i + 1) : end);
    }
    return resultList;
}

//search dictionary
ResultList *searchDictionary1(JNIEnv *env, TrieNode **root, const char *wordSearch) {
    TrieNode *tmp;
    char ch;
    int jlen = 0;
    jchar *jchars = NULL;
    charToJchar(env, wordSearch, &jchars, &jlen);
    return searchDictionary(env, root, jchars, jlen);
}


