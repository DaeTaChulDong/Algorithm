//distance: 시작 정점으로부터의 최단 거리->확정되면 빼옴
//최단 경로는 반드시 최단 경로가 이미 확정된 정점들만을 거쳐서 구성
//각 단계에서 S(found)에 포함되지 않은 정점들 중 거리가 가장 짧으면 S에 추가(최소 경로 확정), 다른 정점들의 distance값 갱신
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType{
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
}   GraphType;

int distance[MAX_VERTICES]; //시작 정점으로부터 각 정점까지의 최단 경로 거리 저장
int found[MAX_VERTICES]; //최단 경로가 이미 발견된 정점들. 집합 S

void shortest_path(GraphType *g, int start){ //시작 정점 start로부터 다른 노드와 최단 경로 거리를 구하는 알고리즘
    int i,u,w;
    for(i=0;i<g->n;i++){
        distance[i]=g->weight[start][i]; //초기 distance값을 start로부터의 거리로 설정
        found[i]=FALSE; //일단 최단 경로가 모두 확정되지 않은 것으로 초기화
    } //초기화
    found[start]=TRUE; //시작 정점은 최단 경로가 확정됨
    distance[start]=0;

    for (i=0; i < g->n-1; i++){ //시작 정점은 제외하고 n-1번 루프 반복
        u=choose(distance, g->n, found); //다음번 최단 경로의 노드로 확정할 노드를 선정하기 위한 함수
        found[u]=TRUE; //새 노드 u 경로 확정
        for(w=0;w<g->n;w++)
            if(!found[w]) //경로가 아직 확정되지 않은 노드만 갱신
                if(distance[u]+g->weight[u][w]<distance[w]) //u를 거치는 시작정점부터 w까지의 거리 < distance[w]면 업데이트
                    distance[w]=distance[u]+g->weight[u][w]; //더 작은 값이면 업데이트, 아니면 그대로
    }//u를 고려하여 나머지 정점과의 distance 갱신
}

int choose(int distance[], int n, int found[]){
    int i,min,minpos;
    min=INT_MAX; //일부러 최솟값을 정수의 최댓값으로 설정해서, INF보다도 크게 설정함
    minpos=-1;
    for(i=0;i<n;i++) //루프 n번
        if(distance[i] < min && !found[i]){ //distance가 minimum보다 작고, 최단 경로가 확정되지 않은 노드 중에서 계속 갱신
            min=distance[i];
            minpos=i;
        }
        return minpos;
}

/*
void shortest_path(GraphType *g, int start){
    int i,u,w;
    for(i=0;i<g->n;i++){
        distance[i]=g->weight[start][i];
        found[i]=FALSE;
    }
    found[start]=TRUE;
    distance[start]=0;

    for(i=0;i< g->n-1; i++){ //루프 n-1번
        u=choose(distance,g->n,found);
        found[u]=TRUE;
        for(w=0;w<g->n;w++) //u 선택 뒤 업데이트를 위한 루프 n번
            if(!found[w])
                if(distance[u]+g->weight[u][w]<distance[w])
                    distance[w]=distance[u]+g->weight[u][w];
    }
}
    => 바깥 루프 n번*안쪽 2n번 = 2n^2. 따라서 시간복잡도는 O(n^2)이 된다.
*/

int main(void){
    GraphType g={7,
    {{0,7,INF,INF,3,10,INF}, //자기 자신(시작 정점)은 0으로 설정
    {7,0,4,10,2,6,INF},
    {INF,4,0,2,INF,INF,INF},
    {INF,10,2,0,11,9,4},
    {3,2,INF,11,0,INF,5},
    {10,6,INF,9,INF,0,INF},
    {INF,INF,INF,4,5,INF,0}}
    };
    shortest_path(&g,0);
    return 0;
}