#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 200

typedef struct{
    char word[MAX_WORD_SIZE];
    char meaning[MAX_MEANING_SIZE];
} element;

typedef struct TreeNode{
    element key;
    struct TreeNode *left, *right;
} TreeNode;
//단어를 구조로 갖는 이진트리로 변환

int compare(element e1, element e2){
    return strcmp(e1.word, e2.word);
}

TreeNode* search(TreeNode *root, element key){
    TreeNode *p=root;
    while(p!=NULL){
        if(compare(key, p->key)==0)
            return p;
        else if(compare(key, p->key)<0)
            p=p->left;
        else if(compare(key, p->key)>0)
            p=p->right;
    }
    return p;
}