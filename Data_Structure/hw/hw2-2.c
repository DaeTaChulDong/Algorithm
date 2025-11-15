/*
<< 과제 2-2 >>
- 다음 프로그램이 올바르게 실행될 수 있도록 주석처리 된 문제(1) ~ 문제(2) 부분에 적절한 코드를 작성하라.
- 작성한 코드를 직접 실행해보며 코드의 동작을 이해한다.
*/

/*
<< 디렉토리 용량 계산 >>
- 이진트리 기반의 디렉토리 자료구조를 구축한다.
- 구축한 디렉토리 자료구조에 대하여 디렉토리의 총 용량을 계산하는 함수를 재귀적으로 작성한다.
*/

#include <stdio.h>
#include <stdlib.h>

// 이진트리 기반 디렉토리 자료구조
typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;

int calc_dir_size(TreeNode *root) {
	int left_size, right_size;
	if (root == NULL) return 0;
	/*
	문제(1)
	// 왼쪽 서브트리 디렉토리 용량 계산 결과를 left_size에 저장	
	*/
	left_size=calc_dir_size(root->left);
	/*
	문제(2)
	// 오른쪽 서브트리 디렉토리 용량 계산 결과를 right_size에 저장	
	*/
	right_size=calc_dir_size(root->right);

	return (root->data + left_size + right_size);
}

// 메인함수
int main(void) {
	TreeNode n4 = { 500, NULL, NULL };
	TreeNode n5 = { 200, NULL, NULL };
	TreeNode n3 = { 100, &n4, &n5 };
	TreeNode n2 = { 50, NULL, NULL };
	TreeNode n1 = { 0, &n2, &n3 };

	printf("디렉토리의 크기=%d\n", calc_dir_size(&n1));
}