//이진트리의 순회: 레벨 순회->트리를 너비 우선 탐색으로 방문
//이진트리를 그래프로 보면, 그래프의 너비 우선 탐색과 동일->큐를 사용하여 구현(재귀함수X)
void level_order(TreeNode *prt){ //prt->root
    QueueType q; 
    //자식노드를 방문하고 싶기 때문에 방문할 자식노드를 큐에 넣어줌
    //자식노드를 순서대로 방문하고 꺼내주는 큐
    init_queue(&q);

    if(prt==NULL) return;

    enqueue(&q,prt); //시작(루트)를 큐에 넣어줌
    while(!is_empty(&q)){ //더이상 자식을 방문해야 할 노드가 없을 때까지
        prt=dequeue(&q); //큐:가장 앞에 있는 거 꺼내옴
        printf(" [%d] ",prt->data); //방문
        if(ptr->left) //자식노드를 방문하고 싶기 때문에, 왼쪽 자식노드를 큐에 저장
            enqueue(&q, prt->left);
        if(ptr->right) //오른쪽 자식노드 큐에 저장
            enqueue(&q, ptr->right);
    } //루프를 방문하면서 노드를 꺼내옴(왼쪽 자식부터 방문됨)
}
//깊이->재귀/너비->큐