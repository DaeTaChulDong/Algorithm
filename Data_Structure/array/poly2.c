#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

typedef struct{
    float coef; //계수
    int expon;  //차수
} polynomial;
polynomial terms[MAX_TERMS]={{8,3},{7,1},{1,0},{10,3},{3,2},{1,0}};

int avail=6;

//두 정수 비교
char compare(int a,int b){
    if (a>b)
        return '>';
    else if (a==b)
        return '=';
    else
        return '<';
}

//새로운 항 다항식에 추가
void attach(float coef, int expon){
    if (avail>=MAX_TERMS){
        fprintf(stderr,"항의 개수가 너무 많음\n");
        exit(1);
    }
    terms[avail].coef=coef;
    terms[avail].expon=expon;
    avail++;
}

void print_poly(int s, int e){
    for(int i=s; i<e;i++)
        print("%3.1fx^%d + ",terms[i].coef, terms[i].expon);
    printf("%3.1fx^%d\n",terms[e].coef,terms[e].expon);
}

void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce){
    float tempcoef;
    *Cs=avail;
    while (As<=Ae&&Bs<=Be)
        switch (compare(terms[As].expon, terms[Bs].expon)){
            case '>':   //A의 차수>B의 차수
                attach(terms[As].coef,terms[As].expon);
                As++;
                break;
            case '=':   //A의 차수==B의 차수
                tempcoef=terms[As].coef+terms[Bs].coef;
                if (tempcoef) // !!최고차항 계수가 0이 되면 아예 안 들어감
                    attach(tempcoef, terms[As].expon);
                As++;
                Bs++;
                break;
            case '<':   //A의 차수<B의 차수
                attach(terms[Bs].coef, terms[Bs].expon);
                Bs++;
                break;
        }
    //for문에서는 이미 계산이 끝난 한 쪽(항 수가 적음)과 반대로 아직 남아있는 반대쪽 다항식의 남은 항들을 붙여주는 것임
    //A의 나머지 항들 이동
    for(; As<=Ae; As++) //A가 남아있는 경우 avail에 다 붙여줌
        attach(terms[As].coef, terms[As].expon);
    //B의 나머지 항들 이동
    for(; Bs<=Be; Bs++) //B가 남아있는 경우 avail에 다 붙여줌
        attach(terms[Bs].coef,terms[Bs].expon);
    *Ce=avail-1;
}

int main(void){
    int As=0, Ae=2, Bs=3, Be=5, Cs, Ce;
    poly_add2(As,Ae,Bs,Be,&Cs,&Ce);
    print_poly(As,Ae);
    print_poly(Bs,Be);
    printf("-------------");
    print_poly(Cs,Ce);
    return 0;
}