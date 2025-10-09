/*
<< 과제 1-2 >>
- 다음 프로그램이 올바르게 실행될 수 있도록 주석처리 된 문제(1) ~ 문제(5) 부분에 적절한 코드를 작성하라.
- 작성한 코드를 직접 실행해보며 코드의 동작을 이해한다.
*/

/*
<< 괄호 체크 >>
- 배열을 활용하여 구현된 스택을 사용하여 주어진 표현식의 괄호 사용이 올바른지 체크한다.
- 표현식에 사용 가능한 괄호의 종류는 소괄호, 중괄호, 대괄호이다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXP_LEN 50 // 검사 가능한 표현식의 최대 길이

/* 스택 정의 시작 */
#define MAX_STACK_SIZE 100
typedef char element;		
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType *s) {
	/*
	문제(1)
	// 스택을 초기화 한다.
	*/
	s->top=-1;
}

int is_empty(StackType *s) {
	/*
	문제(2)
	// 스택이 비어있는지 체크한다.
	*/
	return (s->top==-1);
}

int is_full(StackType *s) {
	/*
	문제(3)
	// 스택이 포화 상태인지 체크한다.
	*/
	return (s->top==(MAX_STACK_SIZE-1));
}

void push(StackType *s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		/*
		문제(4)
		// 스택 가장 위에 item을 삽입한다.
		*/
		s->data[++(s->top)]=item;
	}
}

element pop(StackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		/*
		문제(5)
		// 스택 가장 위의 item을 삭제하고, 삭제한 값을 반환한다.
		*/
		return s->data[(s->top)--];
	}
}
/* 스택 정의 끝 */

/* 괄호 체크 알고리즘 */
int check_matching(const char *in) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);
	init_stack(&s);

	for (i = 0; i < n; i++) {
		ch = in[i];
		switch (ch) {
		case '(':
        case '[':
        case '{':
			push(&s, ch);
			break;
		case ')':
        case ']':
        case '}':
			if (is_empty(&s))
                return 0;
			else {
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') ||
					(open_ch == '[' && ch != ']') ||
					(open_ch == '{' && ch != '}')) {
					return 0;
				}
				break;
			}
		}
	}
	if (!is_empty(&s))
        return 0;
	return 1;
}

int main(void) {
    // 괄호 체크 대상 표현식
    char exprs[][MAX_EXP_LEN] = {
		"{ A[(i+1)]=0; }",
		"((A+B)*C)",
		"{ (A+B] )",
		"(((X+Y)))",
		"[{()}]",
		"{ [ ( ] ) }",
		"[]{}()",
		"{a+(b*c)-(d/e)}",
		"(A+B))",
		"if ( ( i==0 ) ( j==0 )",
		"A [ ( i+1 ] ) =0;"
    };

    int n = sizeof(exprs) / sizeof(exprs[0]); // 표현식 개수

    for (int i = 0; i < n; i++) {
        if (check_matching(exprs[i]) == 1)
            printf("%s -> OK\n", exprs[i]);
        else
            printf("%s -> 오류\n", exprs[i]);
    }
    return 0;
}
