#include <stdio.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct{
    element array[MAX_LIST_SIZE];
    int size;
} ArrayListType;

void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//리스트 초기화
void init(ArrayListType *L){
    L->size=0;  //0개의 값이 저장되어 있다고 선언해주는 게 init의 역할
}

int is_empty(ArrayListType *L){
    return L->size==0;
}

int is_full(ArrayListType *L){
    return L->size==MAX_LIST_SIZE;
}

element get_entry(ArrayListType *L,int pos){
    if(pos<0||pos>=L->size)
        error("위치 오류");
    return L->array[pos];
}

void print_list(ArrayListType *L){
    int i;
    for(i=0;i<L->size;i++)
        printf("%d->",L->array[i]);
        printf("\n");
}

//맨 마지막 삽입하는 경우->맨 끝에 집어넣기만 하면 됨
void insert_last(ArrayListType *L, element item){
    if(L->size >= MAX_LIST_SIZE){
        error("리스트 오버플로우");
    }
    L->array[L->size++]=item;
}

//중간 삽입->들어갈 자리 마련 위해 하나씩 뒤로 밀어줌
void insert(ArrayListType *L, int pos, element item){
    if(!is_full(L) && (pos >=0 )&&(pos<=L->size)){
        for(int i=(L->size-1);i>=pos;i--){
            L->array[i+1]=L->array[i];
        }   //빈칸 만들어줬으면 이제 pos 자리에 item 넣음
        L->array[pos]=item;
        L->size++;
    }
}

element delete(ArrayListType *L, int pos){
    element item;

    if(pos<0||pos>=L->size)
        error("위치 오류");
    item=L->array[pos]; //삭제 원소
    for(int i=pos;i<(L->size-1);i++)
        L->array[i]=L->array[i+1];
    L->size--;
    return item;
}

int main(void){
    ArrayListType list; //배열기반리스트 선언
    init(&list);
    insert(&list,0,10); print_list(&list);
    insert(&list,0,20); print_list(&list); //10은 뒤로 밀림
    insert(&list,0,30); print_list(&list);
    insert_last(&list,40);  print_list(&list);
    delete(&list,0);    print_list(&list);
    return 0;
}

