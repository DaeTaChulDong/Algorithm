#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_DEGREE 101

typedef struct
{
    int degree;             // 차수
    float coef[MAX_DEGREE]; // 계수
} polynomial;

void print_poly(polynomial p)
{
    for (int i = p.degree; i > 0; i--)
        printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
    printf("%3.1f \n", p.coef[p.degree]);
}

polynomial poly_add1(polynomial A, polynomial B)
{
    polynomial C; // 결과 다항식
    int Apos = 0, Bpos = 0, Cpos = 0; //pos:처음에 최고차항에서 시작해서 하나씪 더해지면서 다음으로 높은 차수로 이동해서 계산하게 하는 인덱스
    int degree_a = A.degree;
    int degree_b = B.degree;
    C.degree = MAX(A.degree, B.degree);

while (Apos <= A.degree && Bpos <= B.degree)
{
    if (degree_a > degree_b)
    {
        C.coef[Cpos++] = A.coef[Apos++];
        degree_a--;
    }
    else if (degree_a == degree_b)
    {
        C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
        degree_a--;
        degree_b--;
    }
    else
    {
        C.coef[Cpos++] = B.coef[Bpos++];
        degree_b--;
    }
}
return C;}

int main(void){
    polynomial a={5,{3,6,0,0,0,10}};
    polynomial b={4,{7,0,5,0,1}};
    polynomial c;

    print_poly(a);
    print_poly(b);
    c=poly_add1(a,b);
    printf("------------");
    print_poly(c);
    return 0;
}