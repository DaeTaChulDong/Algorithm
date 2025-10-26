#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct{
    element data[MAX_STACK_SIZE];
    int top;
}   StackType;

int eval(char exp[]){   //exp[]:후위표기수식
    int op1, op2, value, i=0;   
    int len=strlen(exp);
    char ch;
    StackType s;    //스택 선언

    init_stack(&s);
    for(i=0;i<len;i++){
        ch=exp[i];
        if(ch != '+' && ch!='-' && ch!='*' && ch!='/'){ //피연산자라면, 문자0~문자9 정수값
            value=ch-'0';   //ch의 아스키코드-'0'의 아스키코드=>뽑아낸 문자를 정수로 만들어주는 것임
            push(&s, value);
        }
        else{
            //!!!연산할때 분자/분모 때문에 반드시 op2부터 해야 됨에 주의!!!
            op2=pop(&s);
            op1=pop(&s);
            switch(ch){
            case '+': push(&s, op1+op2); break;
            case '-': push(&s, op1-op2); break;
            case '*': push(&s, op1*op2); break;
            case '/': push(&s, op1/op2); break;
            }
        }
    }
    return pop(&s);
}

int main(void){
    int result;
    printf("후위표기식은 82/3-32*+\n");
    result=eval("82/3-32*+");
    printf("결과값은 %d\n", result);
    return 0;
}