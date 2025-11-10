//이진트리 연산: 단말노드의 개수 구하기
//이진트리의 재귀적 구조를 활용하여 재귀함수로 구현

int get_leaf_count(TreeNode *node){ //루트 노드
    int count=0;

    if(node!=NULL){
        if(node->left == NULL && node->right==NULL)
            return 1;
        else
            count=get_leaf_count(node->left) //왼쪽 서브트리의 단말노드 수
                  +get_leaf_count(node->right); //오른쪽 서브트리의 단말노드 수
    }
    return count;
}