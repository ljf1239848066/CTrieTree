#include "trietree.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//build dictionary
void buildDictionary(TrieNode **root) {
    *root = createBranch(NULL, NULL);
}

//create node
TrieNode *createBranch(char *name, char *definition) {
    TrieNode *branch = NULL; //start create the trie and all value is NULL
    branch = (TrieNode *) malloc(sizeof(TrieNode)); //let branch hv same size as trie
    branch->length = 0;
    branch->category = NULL;
    branch->riskLevel = NULL;
    branch->next = NULL; //nextis for sub tree
    return branch;
}

//adding word into dictionary
void addDictionary(TrieNode **root, char *name, char *category, char *riskLevel) { // add word
//    if(NULL == name) {
//        return;
//    }
//    TrieNode *current = *root;
//    int len = strlen(name);
//    for(int i=0;i<len;i++) {
//        char ch = name[i];
//        if(NULL!= current->next) {
//            BSTNode *node = SearchBSTree(current->next), ch);
//            if(SearchBSTree(current->next), ch) {
//
//            }
//        }
//    }
//
//    //for the 1st node
//    if ((*root)->list.child == NULL) {
//        //(*root)->list.child = word;
//        listAdd(&(*root)->list.child, name, definition);
//        return;
//    }
//
//    // more than 1 node
//    listCheckNext(&(*root)->list.child, name, definition);
//    return;
}

//search dictionary
char *searchDictionary(TrieNode **root, char *wordSearch) {
//    char *result;
//    TrieNode *word = NULL;
//    word = (TrieNode *) malloc(sizeof(TrieNode));
//    word = (*root)->list.child;
//    //check word to be search is an actual a word or not
//    if (wordSearch == NULL) {
//        return NULL;
//    }
//
//    int i;
//    //check is there any match word in it
//    if (findFirstIndexOfNoneSameChar(word->name, wordSearch) < 0 && word != NULL) {
//        word = word->list.next;
//    }
//
//    i = findFirstIndexOfNoneSameChar(word->name, wordSearch);
//    //return NULL if there is not such word in dictionary
//    if (word == NULL) {
//        return NULL;
//    }
//    //buffer1 and buffer2 is word to be search
//    //buffer3 and buffer4 is the word in dictionary
//    char *buffer1, *buffer2, *buffer3, *buffer4;
//    buffer1 = createSubString(wordSearch, 0, i + 1);
//    buffer2 = createSubString(wordSearch, i + 1, strlen(wordSearch) - (i + 1));
//    buffer3 = createSubString(word->name, 0, i + 1);
//    buffer4 = createSubString(word->name, i + 1, strlen(word->name) - (i + 1));
//
//    //if there is not fully match between word in dictionary and word to search
//    if (buffer4 != NULL) {
//        free(buffer1);
//        free(buffer2);
//        free(buffer3);
//        free(buffer4);
//        return NULL;
//    }
//
//    //if there are same
//    if (buffer4 == NULL && buffer2 == NULL) {
//        free(buffer1);
//        free(buffer2);
//        free(buffer3);
//        free(buffer4);
//        return (word->definition);
//    }
//
//    result = searchDictionary(&word, buffer2);
//    free(buffer1);
//    free(buffer2);
//    free(buffer3);
//    free(buffer4);
//    return result;

    return nullptr;
}