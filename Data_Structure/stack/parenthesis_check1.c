#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct{
    element data[MAX_STACK_SIZE];
    int top;
}   StackType;

//in->괄호를 포함한 문자열
int check_matching(const char *in){
    StackType s;//사용할 스택
    char ch, open_ch;
    int i,n=strlen(in);
    init_stack(&s);

    for(i=0;i<n;i++){
        ch=in[i];//현재문자
        switch(ch){
        case '(':
        case '[':
        case '{':
            push(&s, ch);
            break;
        case ')':
        case ']':
        case '}':
            if(is_empty(&s))//스택이 비었다면
                return 0;
            else{
                open_ch=pop(&s);
                if((open_ch=='('&&ch!=')')||
                    (open_ch == '[' && ch!= ']') ||
                    (open_ch == '{' && ch!= '}')){
                    return 0; //짝이 안맞다면
                }
                break;
            }
        }
    }
    if (!is_empty(&s))//다 처리했는데 스택이 비어있지 않으면
        return 0;
    return 1;
}

int main(void){
    char *p="{ A[(i+1)]=0; }";
    if(check_matching(p)==1)
        printf("%s 괄호검사성공\n", p);
    else
        printf("%s 괄호검사실패\n", p);
    return 0;
}