typedef int element;
typedef struct DListNode{
    element data;
    struct DListNode *llink;    //선행노드포인터
    struct DListNode *rlink;    //후행노드포인터
}   DListNode;

//초기화:head노드밖에 없어서 일단 rlink->llink, llink->rlink이렇게 자기 스스로를 가리키게 포인터 설정
void init(DListNode *phead){
    phead->llink=phead;
    phead->rlink=phead;
}   //head노드도 llink,data,rlink의 형태로 되어있으나 data가 NULL인 것뿐임

/*
이중연결리스트는 기본적으로 선행노드의 rlink가 내가 되고, 후행노드의 llink가 내가 되기 때문에,
p == p->llink(선행노드)->rlink(선행노드의 rlink==p) == p->rlink(후행노드)->llink(후행노드의 llink==p)가 성립한다.
*/

//전에 있는 노드 before 뒤에 새로운 노드 삽입하고 싶을 때
void dinsert(DListNode *before, element data){
    DListNode *newnode=(DListNode *)malloc(sizeof(DListNode));
    newnode->data=data;
    newnode->llink=before; //붙여줌1 newnode->llink:before노드 가리키게 함
    newnode->rlink=before->rlink;   //붙여줌2 newnode->rlink:후행 노드 가리키게 함
    before->rlink->llink=newnode;   //끊어줌1 후행 노드의 llink가 newnode 가리키게 함
    before->rlink=newnode;  //끊어줌2 before이 newnode를 가리키게 함
}   //순서를 잘 지켜야함. 보통 먼저 붙여주고 나서 끊는데, 주소가 사라질 수도 있기 때문


void ddelete(DListNode *head, DListNode *removed){
    if(removed==head) return;
    removed->llink->rlink=removed->rlink;
    removed->rlink->llink=removed->llink;
    free(removed);
}

int main(void){
    DListNode *head=(DListNode *)malloc(sizeof(DListNode));
    init(head); //head노드 위한 공간 할당 뒤 init에 head 노드 줌
}