/*
힙: 조건부 탐색을 위해 사용함->조건에 맞는 것만 빨리 찾고 싶은 거임(가장 큰 값/가장 작은 값처럼). 우선순위 큐의 구현 목적
임의의 원하는 데이터 탐색/가장 큰,작은 값 탐색 등. 힙은 상수 시간 내 가장 큰,작은값 찾을 수 있음(바로 꺼내올 수 있음)
가장 큰,작은 값이 루트에 있도록 힙은 보장해주기 때문임.->바로 루트에서 가져오면 됨
힙은 완전이진트리를 보장함. 왼쪽부터 꽉 채워져 있어야 함.
조건1.완전이진트리 2.가장 큰/작은값이 루트 2-1.부모노드가 자식노드보다는 커야 함

이진탐색트리의 AVL트리->순차적 탐색을 위한 거였음. 트리의 특성상 AVL로 O(log2N)까지 가능 
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct{
    int key;
} element;

typedef struct{
    element heap[MAX_ELEMENT]; //이 배열 자체가 힙, !!0번 인덱스 없음에 주의!!
    int heap_size; //현재 몇 개 데이터가 저장되어 있는지 정수 변수
} HeapType;

HeapType* create(){
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h){
    h->heap_size=0; //저장된 데이터 0개
}

void insert_max_heap(HeapType* h, element item){
    int i;
    i= ++(h->heap_size);

    while((i!=1) && (item.key > h->heap[i/2].key)){
        h->heap[i] = h->heap[i/2];
        i /=2;
    }
    h->heap[i]=item;
}

element delete_max_heap(HeapType* h){
    int parent, child;
    element item, temp;
    item=h->heap[1];
    temp=h->heap[(h->heap_size)--];
    parent=1;
    child=2;
    while(child <= h->heap_size){
        if((child < h->heap_size) &&
            (h->heap[child].key) < h->heap[child+1].key)
            child++;
        if(temp.key >= h->heap[child].key)
            break;
        h->heap[parent]=h->heap[child];
        parent=child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

void heap_sort(element a[], int n){
    int i;
    HeapType h;

    h=create();
    init(h);
    for (i=0; i<n; i++){
        insert_max_heap(h, a[i]);
    }
    for(i=(n-1); i>=0; i--){
        a[i] = delete_max_heap(h);
    }
    free(h);
}

int main(void){
    element e1={10}, e2={5}, e3={30};
    element e4,e5,e6;
    HeapType* heap;

    heap=create();
    init(heap);
    insert_max_heap(heap,e1);
    insert_max_heap(heap,e2);
    insert_max_heap(heap,e3);

    e4=delete_max_heap(heap);
    printf("< %d > ",e4.key);
    e5=delete_max_heap(heap);
    printf("< %d > ",e5.key);
    e6=delete_max_heap(heap);
    printf("< %d > \n",e6.key);

    free(heap);
    return 0;
}
