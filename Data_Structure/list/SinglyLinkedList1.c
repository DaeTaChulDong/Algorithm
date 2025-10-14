#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;  //나 자신을 가리키고자 하는 포인터
}   ListNode;

ListNode* insert_first(ListNode *head, int value){
    ListNode *p=(ListNode*)malloc(sizeof(ListNode));
    p->data=value;
    p->link=head;   //head는 첫번째 노드의 위치를 가리키던 포인터였기 때문에 p->link가 가리키도록 바꿔줌
    head=p; //head를 p를 가리키게 해서 head->p->원래의첫번째노드 이렇게 삽입. p도 ListNode type의 포인터임.
    return head;
}

//특정 노드 pre 뒤에 원소 삽입
ListNode* insert(ListNode *head, ListNode *pre, element value){
    ListNode *p=(ListNode *)malloc(sizeof(ListNode));
    p->data=value;
    p->link=pre->link;
    pre->link=p;
    return head;
}

ListNode* delete_first(ListNode *head){
    ListNode *removed;
    if (head==NULL) return NULL;
    removed=head;   //일단 안전하게 삭제할 노드를 head 대신 removed로 가리키게 함
    head=removed->link;
    free(removed);
    return head;
}

ListNode* delete(ListNode *head, ListNode *pre){
    ListNode *removed;
    removed=pre->link;
    pre->link=removed->link;
    free(removed);
    return head;
}

//리스트 순회(방문)
void print_list(ListNode *head){
    for(ListNode *p=head;p!=NULL;p=p->link)
        printf("%d->",p->data);
    printf("NULL\n");
}

//리스트에서 특정 값 탐색, 중복 데이터 존재 시 가장 앞쪽에 있는 거 반환
ListNode* search_list(ListNode *head, element x){
    ListNode *p=head;

    while(p!=NULL){
        if(p->data==x)
            return p;
        p=p->link;
    }
    return NULL;
}

//두개의 리스트를 하나의 리스트로 연결
ListNode* concat_list(ListNode *head1, ListNode *head2){
    if(head1==NULL) return head2;
    else if(head2==NULL)    return head2;
    else{
        ListNode *p;
        p=head1;
        while(p->link!=NULL)
            p=p->link;
        p->link=head2;
        return head1;
    }
}

//리스트 역순으로 만들기
ListNode* reverse(ListNode *head){
    ListNode *p,*q,*r;
    //p:원래 리스트 노드가 어떤 리스트인지 현재 노드 알려줌
    //q:최종적인 역순 리스트의 헤드 포인터
    //r:q(역순 리스트)가 가리킬 노드 따로 알려줌
    p=head;
    q=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->link;  //p->q->r순으로 가리키게 함
        q->link=r;
    }
    return q;
}

int main(void){
    ListNode *head=NULL;

    for(int i=0;i<5;i++){
        head=insert_first(head,i);
        print_list(head);
    }
    for(int i=0;i<5;i++){
        head=delete_first(head);
        print_list(head);
    }
    return 0;
}