/*
<< 과제 2-1 >>
- 다음 프로그램이 올바르게 실행될 수 있도록 주석처리 된 문제(1) ~ 문제(8) 부분에 적절한 코드를 작성하라.
- 작성한 코드를 직접 실행해보며 코드의 동작을 이해한다.
*/

/*
<< 수식트리를 활용한 수식출력과 수식계산 >>
- 이진트리 자료구조를 활용하여 수식트리를 구축한다.
- 구축한 수식트리에 대하여 전위/중위/후위수식을 출력하는 함수를 재귀적으로 작성한다.
- 수식의 데이터 출력에는 반드시 아래에 정의된 print_node() 함수를 사용한다.
- 구축한 수식트리에 대하여 수식을 계산하는 함수를 재귀적으로 작성한다.
*/

#include <stdio.h>
#include <stdlib.h>

// 수식트리 자료구조
typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;

// 수식트리의 각 노드 출력 함수
void print_node(int data) {
	if (data == '+' || data == '-' || data == '*' || data == '/') {
		printf("[%c] ", data);
	} else {
		printf("[%d] ", data);
	}
}

// 전위수식 출력 함수
void pre_exp(TreeNode *root) {
	if (root != NULL) {
		/*
		문제(1)
		// 재귀 방식의 전위수식 출력 코드 첫 번째 줄	
		*/
		print_node(root->data);
		/*
		문제(2)
		// 재귀 방식의 전위수식 출력 코드 두 번째 줄	
		*/
		pre_exp(root->left);

		pre_exp(root->right);
	}
}

// 중위수식 출력 함수
void in_exp(TreeNode *root) {
	if (root != NULL) {
		/*
		문제(3)
		// 재귀 방식의 중위수식 출력 코드 첫 번째 줄	
		*/
		in_exp(root->left);
		/*
		문제(4)
		// 재귀 방식의 중위수식 출력 코드 두 번째 줄	
		*/
		print_node(root->data);

		in_exp(root->right);
	}
}

// 후위수식 출력 함수
void post_exp(TreeNode *root) {
	if (root != NULL) {
		post_exp(root->left);
		/*
		문제(5)
		// 재귀 방식의 후위수식 출력 코드 두 번째 줄	
		*/
		post_exp(root->right);
		/*
		문제(6)
		// 재귀 방식의 후위수식 출력 코드 세 번째 줄	
		*/
		print_node(root->data);
	}
}

// 수식계산 함수
int evaluate(TreeNode *root) {
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return root->data;
	else {
		int op1, op2;
		/*
		문제(7)
		// 왼쪽 서브트리의 수식 계산결과를 op1에 저장	
		*/
		op1=evaluate(root->left);
		/*
		문제(8)
		// 오른쪽 서브트리의 수식 계산결과를 op2에 저장	
		*/
		op2=evaluate(root->right);

		printf("%d %c %d을 계산합니다.\n", op1, root->data, op2);
		switch (root->data) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
		}
	}
	return 0;
}

// 메인함수
int main(void) {

	//		     +
	//	     *		 +
	//    1	   4   16  25

	TreeNode n1 = { 1,  NULL, NULL };
	TreeNode n2 = { 4,  NULL,  NULL };
	TreeNode n3 = { '*',  &n1,  &n2 };
	TreeNode n4 = { 16, NULL, NULL };
	TreeNode n5 = { 25, NULL, NULL };
	TreeNode n6 = { '+', &n4,  &n5 };
	TreeNode n7 = { '+', &n3,  &n6 };
	TreeNode *exp = &n7;

	printf("### 전위수식 출력: ");
	pre_exp(exp);
	printf("\n");
	printf("### 중위수식 출력: ");
	in_exp(exp);
	printf("\n");
	printf("### 후위수식 출력: ");
	post_exp(exp);
	printf("\n");
	printf("*** 최종 수식 계산 결과: %d\n", evaluate(exp));
	return 0;
}