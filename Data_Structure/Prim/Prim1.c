//구현: 가중치 그래프 정의 및 필요한 배열 선언
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100 //각 정점의 수 (최대치)
#define INF 1000L //일부러 엄청 큰 숫자 설정해서, 연결이 없는 간선에 infinite number로 가중치 설정하기 위함

typedef struct GraphType{ //가중치 그래프 자료구조, 인접행렬->가중치 저장
    int n; //정점의 개수
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int selected[MAX_VERTICES]; //selected->각 정점이 최소 스패닝 트리에 포함되는지의 여부 표시. 정점이 최소 스패닝 트리에 포함되면 1 없으면 0으로 표시
int distance[MAX_VERTICES]; //distance->현재 최소 스패닝 트리로부터 각 정점까지의 거리 표시. 현재 최소 스패닝 트리에서 각 정점까지의 거리에 대한 데이터 저장

void prim(GraphType *g, int s){ //s:시작 정점
    int i,u,v;

    for(u=0;u<g->n;u++) //n:모든 정점의 개수. 즉 모든 정점의 개수만큼 반복을 시작
        selected[u]=FALSE; //알고리즘을 계산하기 전 모든 정점을 초기화
    
    for(u=0;u<g->n;u++) //n번 루프
        distance[u]=INF; //모든 간선 초기화(연결X 상태로)

    distance[s]=0; //s:시작 정점, 거리를 0으로 설정

    for(i=0;i<g->n;i++){ //루프로 알고리즘 구현. n번 반복 시행
        u=get_min_vertex(g->n); //스패닝 트리에 새롭게 추가될 정점 선택
        selected[u]=TRUE; //최소 스패닝 트리에 선택되어 포함된 정점을 TRUE로 바꿔줌
        if(distance[u]==INF) //추가:연결이 안 되었으면 return
            return;
        printf("정점 %d 추가\n",u); //트리에 정점 추가되었다고 알림
        for(v=0;v<g->n;v++) //distance 업데이트(스패닝 트리로부터의 거리 갱신)
            if(g->weight[u][v] !=INF)
                if(!selected[v] && g->weight[u][v]<distance[v])
                    distance[v]=g->weight[u][v];
    }
}
/*
거리는 연결되어 있어야 측정할 수 있음. 
distance: 스패닝 트리로부터 각 정점의 거리. 스패닝 트리 갱신마다 distance vertor를 갱신할 필요가 있음.
*/

//스패닝 트리에 새롭게 추가될 정점 탐색
int get_min_vertex(int n){
    int v,i;
    for(i=0;i<n;i++)
        if(!selected[i]){
            v=i;
            break;
        }
    for(i=0;i<n;i++)
        if(!selected[i] && (distance[i]<distance[v]))
            v=i;
    return (v);
}

int main(void){
    GraphType g={7,
    {{0,29,INF,INF,INF,10,INF},
    {29,0,16,INF,INF,INF,15},
    {INF,16,0,12,INF,INF,INF},
    {INF,INF,12,0,22,INF,18},
    {INF,INF,INF,22,0,27,25},
    {10,INF,INF,INF,27,0,INF},
    {INF,15,INF,18,25,INF,0}}
    };
    prim(&g,0);
    return 0;
}
