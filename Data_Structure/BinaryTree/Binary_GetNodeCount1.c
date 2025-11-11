//이진트리 연산1: 노드 개수 구하기(이진트리를 구성하는 전체 노드의 개수)
//이진트리의 재귀적 구조를 활용하여 재귀함수로 구현한다.
int get_node_count(TreeNode *node){ //루트 노드
    int count=0;

    if(node!=NULL)
        count = 1+get_node_count(node->left) //자기 자신(루트) 1 + 왼쪽 서브트리의 전체 노드 수
                 +get_node_count(node->right); //오른쪽 서브트리의 전체 노드 수
    
    return count;
}