/*입력이 피연산자->결과에 출력/연산자->스택에 push
단 스택에는 우선순위 높은 연산자 위에 우선순위 낮은 연산자가 오면 안 됨
즉 우선순위 낮은 연산자보다 우선순위 높은 연산자가 결과식에 먼저 출력되어야 함*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXP_LEN 50 //변환 가능한 중위표기수식의 최대 길이
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct{
    element data[MAX_STACK_SIZE];
    int top;
}   StackType;

int prec(char op){  //연산자 간 우선순위 도출
    switch(op){
    case '(':
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}

for(i=0;i<len;i++){
    ch=exp[i];
    switch(ch){
        case '+':
        case '-':
        case '*':
        case '/':
            while (!is_empty(&s) && (prec(ch)<=prec(peek(&s))))
                printf("%c", pop(&s));
            push(&s, ch);
            break;
        case '(':
            push(&s, ch);
            break;
        case ')':
            top_op=pop(&s);
            while(top_op != '(');{
                printf("%c", top_op);
                top_op=pop(&s);
            }
            break;
        default:
            printf("%c", ch);
            break;
        }
}
while (!is_empty(&s))
    printf("%c", pop(&s));

void infix_to_postfix(char exp[]){
    int i=0;
    char ch, top_op;
    int len=strlen(exp);

    StackType s;
    init_stack(&s);
}