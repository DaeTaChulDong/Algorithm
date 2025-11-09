//이진트리 연산2: 높이 구하기
//이진트리의 재귀적 구조를 활용하여 재귀함수로 구현한다.
int get_height(TreeNode *node){ //루트 노드
    int height=0;

    if(node!=NULL)
        height = 1+max(get_height(node->left), get_height(node->right));
    
    return height;
}