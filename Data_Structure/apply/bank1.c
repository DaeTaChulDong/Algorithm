#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int id;
    int arrival_time;
    int service_time;
}   element;

#define MAX_QUEUE_SIZE 5
typedef struct{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
}   QueueType;

int main(void){
    int minutes=30; //주어진 시간 30분
    int total_wait=0; //총 대기시간
    int total_customers=0; //총 고객수
    int service_time=0; //현재 처리중인 고객의 남은 서비스 시간
    int service_customer; //현재 처리중인 고객 ID

    QueueType queue; //원형 큐 생성
    init_queue(&queue);

    srand(time(NULL)); //랜덤을 seed를 현재시각으로 줘서 난수 생성함
    //시뮬레이션 루프
    for(int clock=0;clock<minutes;clock++){ //clock:현재시각, minutes:남은시간 30분, 루프마다 1분씩 지남
        printf("현재시각=%d\n", clock);
        if((rand()%10)<3){ //랜덤으로 새로운 고객이 도착했다면 큐에 줄을 세움
            element customer;  //큐에 줄세울 새 고객 구조체 생성
            customer.id=total_customers++;
            customer.arrival_time=clock;
            customer.service_time=rand()%3+1; //여기까지 고객 생성
            enqueue(&queue, customer); //큐에 줄세움
            printf("고객 %d이 %d분에 들어옵니다. 업무처리시간=%d분\n",
                customer.id, customer.arrival_time,customer.service_time);   
        } //고객 도착과 관련
        if(service_time>0){ //현재 서비스 중인 고객이 있다면
            printf("고객 %d 업무처리중입니다. \n",service_customer);
            service_time--; //시간이 흘러감
        } //고객 도착과 무관하게 고객 서비스1
        else{ //서비스 중인 고객이 없다면
            if(!is_empty(&queue)){ //큐에 줄 서있다면
                element customer=dequeue(&queue); //다음 고객을 꺼내옴
                service_customer=customer.id; //현재 처리 고객 표시
                service_time=customer.service_time;
                printf("고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n",
                    customer.id,clock,clock-customer.arrival_time);
                total_wait +=clock-customer.arrival_time; //전체 대기 시간 갱신
            }
        } //고객 서비스2
    }
    /*시뮬레이션 루프
    루프 1번당 1분이 지났다고 가정함. 실제로는 정수값
    난수 생성하여 3 미만이면 새로운 고객이 들어왔다고 판단(도착 랜덤 시뮬레이션)->큐에 새 구조체 추가
    service_time이 0이 아닌 경우->현재 서비스 중인 고객이 있음. 루프 1번당 1분씩 감소
    service_time이 0인 경우->현재 서비스 받는 고객이 없음. 원형 큐에서 새로운 고객을 꺼내 시작
    */

    printf("전체 대기 시간=%d분 \n", total_wait);
    printf("평균 대기 시간=%.2f분 \n", (float)total_wait/total_customers);
    return 0;
}
