//원형 연결 리스트의 처음/끝에 새로운 원소 삽입
ListNode* insert_last(ListNode* head, element data){
    ListNode *node=(ListNode *)malloc(sizeof(ListNode)); //삽입할 노드를 가리킬 포인터 생성 필요
    node->data=data;
    if(head==NULL){
        head=node;
        node->link=head;
    }
    else{
        node->link=head->link;
        head->link=node;
        head=node;  //삽입한 원소를 마지막 노드로 설정
    }
    return head;
}