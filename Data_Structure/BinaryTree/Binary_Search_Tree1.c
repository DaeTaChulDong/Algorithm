//이진탐색트리 구현-중위순회로
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode{
    element key; //실제 데이터(키값)
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* new_node(int item){ //item: 데이터
    TreeNode *temp=(TreeNode *)malloc(sizeof(TreeNode));
    temp->key=item;
    temp->left=temp->right=NULL; //주어진 정보가 없으므로 NULL로 설정하여 뉴 노드(트리) 생성
    return temp;
}

void inorder(TreeNode *root){ //중위 순회 구현: 왼-루트-오른
    if(root){
        inorder(root->left);
        printf("[%d]", root->key);
        inorder(root->right);
    }
}

//주요 연산1: 탐색(재귀적 구현)
TreeNode* search(TreeNode *node, int key){ //node:루트, key:검색값
    if(node==NULL)
        return NULL;
    if(key==node->key) //내가 원하는 값 탐색 완료, 값 반환
        return node;
    else if(key < node->key) //키 값이 더 작으면 왼쪽 노드를 탐색
        return search(node->left, key);
    else //키 값이 더 크면 오른쪽 노드를 탐색
        return search(node->right, key);
}

//탐색(반복적 구현)
TreeNode* search(TreeNode *node, int key){ //root:탐색할 서브트리의 루트 key:찾는 값
    while(node!=NULL){
        if(key==node->key)
            return node; //값 찾으면 노드 반환
        else if(key< node->key) //키가 더 작은 값이면 왼쪽 감
            node=node->left;
        else
            node=node->right;
    }
    return NULL;
}

//삽입은 탐색을 먼저 수행한 뒤, 삽입하고자 하는 원소가 탐색에 성공하면 이미 존재하기에 삽입 불가(트리는 같은 값 중복 저장X)
//원소 탐색에 실패했다면, 탐색이 실패한 위치에 원소를 삽입한다.
TreeNode* insert_node(TreeNode *root, int key){ //root:삽입할 서브트리의 대표루트, key:삽입할 값
    if(root==NULL)
        return new_node(key);
    
        if(key<root->key)
            root->left=insert_node(root->left, key); //삽입완료된 서브트리가 있다면 루트 알려달라(key 넣은 루트 주면 추가)
        else if(key>root->key)
            root->right=insert_node(root->right, key);
        return root;
}
//같은 리턴값이어도 삽입 전/후의 루트로 의미가 다르다.

TreeNode* min_value_node(TreeNode *node){
    TreeNode *current=node;

    while(current->left!=NULL)
        current=current->left;

    return current;
}

TreeNode* delete_node(TreeNode *root, int key){
    if(root==NULL) return root;

    if(key<root->key)
        root->left=delete_node(root->left,key);
    else if(key>root->key)
        root->right=delete_node(root->right,key);
    else{
        if(root->left==NULL){ //삭제되어야 하는데 자식 있는 채로 없애면 안 되니까
            TreeNode *temp=root->right; //왼쪽 자식이 없으면 오른쪽 자식 반환해줌
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            TreeNode *temp=root->left;
            free(root);
            return temp;
        }
        TreeNode *temp=min_value_node(root->right);
        root->key=temp->key;
        root->right=delete_node(root->right,temp->key);
    }
    return root;
}

