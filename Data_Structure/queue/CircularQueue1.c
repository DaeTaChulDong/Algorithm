/* 원형 큐: 원형 큐는 선형 큐 배열의 인덱스를 원형으로 순환하여 접근하는 방식을 사용함.
이때 %(나머지)를 사용함.
[0],[1],등은 단순한 인덱스 번호가 아니라 나머지로, 빙글빙글 돌면서 사용할 수 있게끔 함.*/
#include <stdio.h>

#define MAX_QUEUE_SIZE 5
//원형 큐: 고정된 크기의 배열 활용

typedef int element;
typedef struct{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
}   QueueType;

void init_queue(QueueType *q){
    q->front=q->rear=0; //선형큐는 front를 -1, 원형큐는 0으로 초기화
} 
/*
원형큐는 음수 인덱스가 존재하지 않기에 1번 인덱스부터 저장된다.
따라서 한 칸의 인덱스는 front와 rear를 관리하기 위해 실질적으로 사용하지 않고 ,
size-1만큼만 데이터를 저장하는데 사용할 수 있다.
*/

void enqueue(QueueType *q, element item){
    if(is_full(q))
        error("큐가 포화상태입니다.");
    q->rear=(q->rear+1)%MAX_QUEUE_SIZE; //나머지에 매핑하여 순환 인덱스 구현
    q->data[q->rear]=item;
}

element dequeue(QueueType *q){
    if(is_empty(q))
        error("큐가 공백상태입니다.");
    q->front=(q->front+1)&MAX_QUEUE_SIZE;
    return q->data[q->front];
}

int is_empty(QueueType *q){
    return (q->front==q->rear); //반드시 인덱스가 0인경우가 아니어도 비어있다 볼 수 있음
}

int is_full(QueueType *q){
    return ((q->rear+1)%MAX_QUEUE_SIZE==q->front);
} //마지막 원소[rear]의 위치가 반드시 MAX_QUEUE_SIZE-1은 아닐 수도 있다. +1(%큐사이즈)했는데 front이면 꽉 찬 것

int main(void){
    QueueType queue;
    int element;

    init_queue(&queue);
    printf("--데이터 추가 단계--\n");
    while(!is_full(&queue)){
        printf("정수를 입력하시오: ");
        scanf("%d", &element);
        enqueue(&queue, element);
        queue_print(&queue);
    }
    printf("큐는 포화상태입니다.\n\n");

    printf("--데이터 삭제 단계--\n");
    while(!is_empty(&queue)){
        element=dequeue(&queue);
        printf("꺼내진 정수: %d \n", element);
        queue_print(&queue);
    }
    printf("큐는 공백상태입니다.\n");
    return 0;
}