//이진트리의 표현: 포인터 사용
//구조체에 왼쪽 자식 노드/오른쪽 자식 노드를 가리킬 수 있는 포인터를 가진다.

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{ //트리의 노드 구조체
    int data; //element type으로 해도 괜찮음
    struct TreeNode *left, *right; //왼쪽 오른쪽 자식을 가리키는 포인터
} TreeNode;

int main(void){
    //생성할 노드 개수만큼 선언하고 공간 생성
    TreeNode *n1, *n2, *n3;

    n1=(TreeNode *)malloc(sizeof(TreeNode));
    n2=(TreeNode *)malloc(sizeof(TreeNode));
    n3=(TreeNode *)malloc(sizeof(TreeNode));

    n1->data=10;
    n1->left=n2;
    n1->right=n3;

    n2->data=20;
    n2->left=NULL;
    n2->right=NULL;

    n3->data=30;
    n3->left=NULL;
    n3->right=NULL;

    free(n1); free(n2); free(n3);
    return 0;
}