#include <stdio.h>

#define MAX_QUEUE_SIZE 5

//선형 큐: 고정된 크기의 배열 활용
typedef int element;
typedef struct{
    int front;  //맨앞쪽원소-가장 앞원소의 하나 앞이어야 함
    int rear;   //맨뒷쪽원소
    element data[MAX_QUEUE_SIZE];
}   QueueType;

void init_queue(QueueType *q){
    q->rear=-1;
    q->front=-1;
}

void enqueue(QueueType *q,int item){
    if(is_full(q)){
        error("큐가 포화상태입니다.");
        return;
    }
    q->data[++(q->rear)]=item; //큐의 삽입은 항상 rear 쪽에서 일어남
}

int dequeue(QueueType *q){
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
        return -1;
    }
    int item=q->data[++(q->front)]; //삭제는 항상 앞쪽에서 일어남
    return item; //실제로 값은 남아있지만, 이 큐의 정의상 front가 이동하면 삭제한 걸로 침
}   //정의상 q->data[front+1]부터 첫번째 원소로 침

int is_empty(QueueType *q){
    if(q->front==q->rear)   //front==rear면 원소가 0개인 것
        return 1;
    else
        return 0;
}
//front는 [첫번째원소-1]일거고 rear는 [마지막원소]일것이기 때문임

int is_full(QueueType *q){
    if(q->rear==MAX_QUEUE_SIZE-1) //가장마지막원소가 맨끝까지 차있음
        return 1;
    else
        return 0;
}

int main(void){
    int item=0;
    QueueType q;

    init_queue(&q);

    enqueue(&q,10); queue_print(&q);
    enqueue(&q,20); queue_print(&q);
    enqueue(&q,30); queue_print(&q);

    item=dequeue(&q);   queue_print(&q);
    item=dequeue(&q);   queue_print(&q);
    item=dequeue(&q);   queue_print(&q);
    return 0;
}

/*
선형 큐의 문제점: 인덱스가 계속 뒤로 밀려서 앞에 빈 공간이 생김.
이를 보완하기 위해 주기적인 원소 이동이 필요한데, 
원형 큐는 선형 큐 배열의 인덱스를 원형으로 순환하여 접근하는 방식을 사용한다.
*/