//크루스컬-> 사이클 확인을 위해 집합 사용(트리 기반) 필요
//최소 가중치 그래프의 정렬된 간선 집합에서 간선 새롭게 추가할 때 최소 가중치 경로이면서 + 사이클 생성되지 않는지 체크 필요
//가중치 오름차순으로 정렬, 사이클 생기면 선택X
//사이클이 생기는지는 서로 다른 집합인지(연결되는 부분이 없는 경우)로 (아니면 같은 스패닝 트리(같은 집합)에 이미 포함되어 있음) 확인
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES]; //집합->각 원소의 부모노드 저장

void set_init(int n){ //집합 데이터 초기화
    for(int i=0;i<n;i++)
        parent[i]=-1; //최소 스패닝 트리에 의한 연결이 없기에 모든 노드는 자기 자신이 루트
}

//union-find 연산의 구현
//각 집합은 개념적으로 하나의 트리의 계층구조로 생각하고, 집합을 대표하는 루트가 존재한다고 생각해야 함
//N번 노드는 N번 노드가 대표인 집합에 속해있다고 말하고 싶은 것이기 때문이다.
//개념적 트리 개념 활용->각 집합이 개념적으로 하나의 트리->집합을 대표하는 루트(대표 노드) 존재->나머지 원소는 루트의 자손 노드가 됨
//트리 자료구조는 배열 이용하여 구현->부모 노드(대표 노드)만 인덱스의 값으로 적어줌
//루트(부모 노드)까지 계속 추적하여 어느 루트 소속인지 소속 집합 판단. 값이 -1면 부모 노드로 판단
int set_find(int curr){ //curr: 소속을 알고 싶은 노드 번호
    if(parent[curr]==-1)
        return curr;
    while (parent[curr] != -1)
        curr=parent[curr];
    return curr; //curr이 속한 루트의 번호 반환
} //find 연산: 원소가 속한 집합을 반환하여, 사이클 여부를 확인할 수 있도록 함

void set_union(int a, int b){ //간선을 추가했다면 두 노드를 같은 집합으로 반영해주어야 함
    int root1=set_find(a);
    int root2=set_find(b);
    if(root1 !=root2)
        parent[root1]=root2; //합쳐줄거면 한 루트를 다른 루트의 자식으로 넘겨줌->root1의 값을 root2의 값으로 바꿔줌
} //union 연산

//간선 기반의 그래프 자료구조
struct Edge{
    int start, end, weight; //시작정점, 끝정점, 가중치
};
typedef struct GraphType{
    int n; //간선의 수
    struct Edge edges[2*MAX_VERTICES];
} GraphType;

//간선 기반의 그래프 자료구조를 활용한 그래프 구축에 필요한 연산
void graph_init(GraphType *g){
    g->n=0;
    for(int i=0; i<2*MAX_VERTICES; i++){
        g->edges[i].start=0;
        g->edges[i].end=0;
        g->edges[i].weight=INF;
    }
}

void insert_edge(GraphType *g, int start, int end, int w){
    g->edges[g->n].start=start;
    g->edges[g->n].end=end;
    g->edges[g->n].weight=w;
    g->n++;
}

void kruskal(GraphType *g){ //크루스컬의 알고리즘
    int edge_accepted=0; //현재까지 선택된 간선의 개수
    int uset, vset; //선택된 간선을 구성하는 노드 u와 v의 소속집합(해당 집합의 루트)
    struct Edge e;

    set_init(g->n); //집합 데이터 초기화
    qsort(g->edges, g->n, sizeof(struct Edge), compare); //퀵소트로 가중치 오름차순으로 간선정렬->매번 최소가중치 선택
    //정렬할 배열의 시작주소, 원소개수, 원소크기, 비교함수
    int i=0;
    while (edge_accepted < (g->n -1)){
        e=g->edges[i]; //정렬 끝난 배열(가중치 오름차순 정렬 완료)
        uset=set_find(e.start); //간선 시작 정점-소속 집합 확인
        vset=set_find(e.end); //간선 끝 정점-소속 집합 확인
        if(uset != vset){ //시작 정점 번호-끝 정점 번호 구해서 비교: 같으면 같은 집합이기에 사이클 생겨서 서로 달라야 한다.
            printf("간선 (%d,%d) %d 선택\n", e.start, e.end, e.weight); //서로 집합 다르면->최소 스패닝 트리에 간선 추가
            edge_accepted++;
            set_union(uset, vset); //시작정점 집합과 끝정점 집합을 하나의 집합으로 합집합해줌
        }
        i++;
    }

}

int compare(const void *a, const void *b){
    struct Edge *x=(struct Edge *)a;
    struct Edge *y=(struct Edge *)b;
    return (x->weight - y->weight);
} //가중치의 오름차순으로 간선들을 정렬 by 퀵정렬 라이브러리 함수

int main(void){
    GraphType *g;
    g=(GraphType *)malloc(sizeof(GraphType));
    graph_init(g);

    insert_edge(g,0,1,29);
    insert_edge(g,1,2,16);
    insert_edge(g,2,3,12);
    insert_edge(g,3,4,22);
    insert_edge(g,4,5,27);
    insert_edge(g,5,0,10);
    insert_edge(g,6,1,15);
    insert_edge(g,6,3,18);
    insert_edge(g,6,4,25);

    kruskal(g);
    free(g);
    return 0;
}
