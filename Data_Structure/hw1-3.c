/*
<< 과제 1-3 >>
- 다음 프로그램이 올바르게 실행될 수 있도록 주석처리 된 문제(1) ~ 문제(4) 부분에 적절한 코드 또는 후위표기수식을 작성하라.
- 작성한 코드를 직접 실행해보며 코드의 동작을 이해한다.
*/

/*
<< 후위표기수식계산 >>
- 배열을 활용하여 구현된 스택을 사용하여 주어진 후위표기수식을 계산한다.
- 지원 가능한 연산자는 C언어의 +, -, *, / 이다.
- 피연산자는 0 ~ 9의 단자리 정수이다.
*/

/*
[[[ 변환조건 ]]]
* 주석으로 주어진 중위표기수식을 후위표기수식으로 변환 시, 다음의 조건을 만족하도록 한다.
- 연산자 우선순위는 *와 /가 +와 -보다 높으며,
- 모든 연산자는 왼쪽 결합을 따른다.
- 즉, 연산자의 왼쪽 및 오른쪽 피연산자 순서는 주어진 중위표기수식 내의 의미와 동일해야 한다.
- 또한, 동일 우선순위의 연산자 역시, 주어진 중위표기수식 내의 등장 순서를 유지해야 한다.
- 괄호를 통해 명시된 우선순위 역시 지켜져야 한다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXP_LEN 50 // 검사 가능한 후위표기수식의 최대 길이

/* 스택 정의 시작 */
#define MAX_STACK_SIZE 100
typedef int element;	
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType *s) {
	s->top = -1;
}

int is_empty(StackType *s) {
	return (s->top == -1);
}

int is_full(StackType *s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
        s->data[++(s->top)] = item;
}

element pop(StackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
        return s->data[(s->top)--];
}
/* 스택 정의 끝 */

/* 후위표기수식 계산 알고리즘 */
int eval(char exp[]) {
	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch;
	StackType s;

	init_stack(&s);
	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			value = ch - '0';
			push(&s, value);
		}
		else {
			/*
			문제(1)
			// 아래 코드를 통해서 계산할 피연산자 두 개를 스택으로부터 pop한다.
			*/
			op2=pop(&s);
			op1=pop(&s);
			switch (ch) {
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2); break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);
}

int main(void) {
	// 체크할 후위표기수식 (/는 C언어의 정수나눗셈 연산자이다.)
    char exprs[][MAX_EXP_LEN] = {
		"23+",         // (2 + 3) -> 답: 5
        
		/*문제(2) 한 줄 주석의 중위표기수식을 문제 코드 최상단에 기재된 변환조건을 만족하도록 변환한 유일한 후위표기수식을 아래 문자열 기호 안에 기재한다.*/
		"512+4*+3-",   // (5 + ((1 + 2) * 4)) - 3 -> 답: 14
        
		"723*-",       // (7 - (2 * 3)) -> 답: 1
		
		/*문제(3) 한 줄 주석의 중위표기수식을 문제 코드 최상단에 기재된 변환조건을 만족하도록 변환한 유일한 후위표기수식을 아래 문자열 기호 안에 기재한다.*/
        "83/2+",       // (8 / 3) + 2 -> 답: 4
        
		"951+/",       // 9 / (5 + 1) -> 답: 1
        "62/34+*",     // (6 / 2) * (3 + 4) -> 답: 21
        "425*+1-",     // (4 + (2 * 5)) - 1 -> 답: 13
		
		/*문제(4) 한 줄 주석의 중위표기수식을 문제 코드 최상단에 기재된 변환조건을 만족하도록 변환한 유일한 후위표기수식을 아래 문자열 기호 안에 기재한다.*/
        "34+25*/",     // (3 + 4) / (2 * 5) -> 답: 0
        
		"813-*2/",     // ((8 * (1 - 3)) / 2 -> 답: -8
        "234*+5/"      // (2 + (3 * 4)) / 5 -> 답: 2
    };

    int n = sizeof(exprs) / sizeof(exprs[0]); // 후위표현수식 개수

	int result; // 후위표현수식 계산 결과
    for (int i = 0; i < n; i++) {
        result = eval(exprs[i]);
		printf("%s = %d\n", exprs[i], result);
    }
    return 0;
}