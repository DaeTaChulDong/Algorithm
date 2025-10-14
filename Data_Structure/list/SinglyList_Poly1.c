
//다항식 표현
typedef struct ListNode{
    int coef;
    int expon;
    struct ListNode *link;
}   ListNode;

//insert_last() 연산의 효율적 구현을 위해 헤더 노드 도입
typedef struct ListType{
    int size;
    ListNode *head;
    ListNode *tail;
}   ListType;

//ListType 헤더 노드는 head 포인터 역할의 특별한 노드로, size(길이), head, tail로 구성됨
//헤더 노드의 head 부분은 시작 노드, tail 부분은 끝 노드를 가리키는 포인터
ListType* create(){
    ListType *plist=(ListType *)malloc(sizeof(ListType));
    plist->size=0;
    plist->head=plist->tail=NULL;
    return plist;
}

ListType *list1, *list2, *list3;

//연결 리스트 헤더 생성
list1=create();
list2=create();
list3=create();

void insert_last(ListType *plist, int coef, int expon){
    ListNode *temp=(ListNode *)malloc(sizeof(ListNode));
    if (temp==NULL){
        error("메모리 할당 에러");
    }
    temp->coef=coef;
    temp->expon=expon;
    temp->link=NULL;
    if(plist->tail==NULL){
        plist->head=plist->tail=temp;
    }
    else{
        plist->tail->link=temp;
        plist->tail=temp;
    }
    plist->size++;
}

insert_last(list1,3,12);
insert_last(list1,2,8);
insert_last(list1,1,0);

void poly_add(ListType *plist1, ListType *plist2, ListType *plist3){
    ListNode *a=plist1->head;
    ListNode *b=plist2->head;
    int sum;

    while(a&&b){
        if(a->expon==b->expon){
            sum=a->coef+b->coef;
            if(sum!=0)  insert_last(plist3, sum, a->expon);
            a=a->link; b=b->link;
        }
        else if(a->expon > b->expon){
            insert_last(plist3, a->coef, a->expon);
            a=a->link;
        }
        else{
            insert_last(plist3, b->coef, b->expon);
            b=b->link;
        }
    }

    for(; a!=NULL; a=a->link)
        insert_last(plist3, a->coef, a->expon);
    for(; b!=NULL; b=b->link)
        insert_last(plist3, b->coef, b->expon);
}