//이진트리의 순회: 후위 순회 LRV
void postorder(TreeNode *root){
    if(root!=NULL){
        postorder(root->left); //왼쪽서브트리 순회
        postorder(root->right); //오른쪽서브트리 순회
        printf("[%d]", root->data); //노드 방문 후 처리: 출력 (응용문제에서는 필요한 연산 처리)
    }
}
//루트를 바로 출력하지 않기에 서브트리 구성에 집중하기