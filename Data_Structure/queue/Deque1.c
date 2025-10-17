//원형 덱의 구현: 고정된 크기의 배열 활용
//정의 및 초기화-상태 체크-후단삽입-전단삭제->원형 큐와 동일

#define MAX_DEQUE_SIZE 5

typedef int element;
typedef struct{
    element data[MAX_DEQUE_SIZE];
    int front,rear;
}   DequeType;

void init_deque(DequeType *q){
    q->front=q->rear=0;
}

int is_empty(DequeType *q){
    return (q->front==q->rear);
}

int is_full(DequeType *q){
    return ((q->rear+1)%MAX_DEQUE_SIZE==q->front);
}

void add_rear(DequeType *q, element item){
    if(is_full(q))
        error("덱이 포화상태입니다.");
    q->rear=(q->rear+1)%MAX_DEQUE_SIZE;
    q->data[q->rear]=item;
}

element delete_front(DequeType *q){
    if(is_empty(q))
        error("덱이 공백상태입니다.");
    q->front=(q->front+1)%MAX_DEQUE_SIZE;
    return q->data[q->front];
}

//후단삭제-전단삽입->원형 덱에 새롭게 추가되는 연산. 인덱스의 반대 방향 순환 필요
void add_front(DequeType *q, element val){
    if(is_full(q))
        error("덱이 포화상태입니다.");
    q->data[q->front]=val;
    q->front=(q->front-1+MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}

element delete_rear(DequeType *q){
    int prev=q->rear;
    if(is_empty(q))
        error("덱이 공백상태입니다.");
    q->rear=(q->rear -1 +MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    return q->data[prev];
}