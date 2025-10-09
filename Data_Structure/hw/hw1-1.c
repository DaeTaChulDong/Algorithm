/*
<< 과제 1-1 >>
- 다음 프로그램이 올바르게 실행될 수 있도록 주석처리 된 문제(1) 부분에 적절한 코드를 작성하라.
- 작성한 코드를 직접 실행해보며 코드의 동작을 이해한다.
- 수업 시간에 배운 dinsert 함수와 과제의 dinsert 함수 구현의 차이를 이해한다.
*/

/*
<< 이중연결리스트 활용: 음악 앱 재생목록 기능 >>
- 원하는 곡명을 저장하고 재생할 수 있는 재생목록 기능을 시뮬레이션 해 본다.
- 재생목록은 이중연결리스트로 구성한다.
- 사용자는 "<" 와 ">" 를 입력하여 앞뒤로 곡을 재생할 수 있다.
- 곡을 탐색함에 따라 현재 재생 중인 곡명이 *** 기호 안에 강조되어 출력된다.
- 재생목록의 끝에 도달하였을 때 ">" 를 누르면 다시 첫 곡을 순환적으로 재생할 수 있다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100]; // 곡명
typedef struct DListNode {
	element data;
	struct DListNode *llink;
	struct DListNode *rlink;
} DListNode;

void init(DListNode *phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void print_playlist(DListNode *phead, DListNode *current) {
	DListNode *p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		if (p == current)
			printf("<-| *** %s *** |-> ", p->data);
		else
			printf("<-| %s |-> ", p->data);
	}
	printf("\n");
}

/*
마지막 삽입한 노드를 반환함으로써, 해당 노드 오른쪽에 다음 노드의 삽입이 가능하도록 하였다.
수업 자료의 코드와 같이 마지막 삽입한 노드를 반환하지 않는다면,
유일하게 주소를 알 수 있는 헤드 노드 오른쪽에만 삽입 가능하여,
결과적으로 재생목록이 리스트 삽입 역순으로 구성되기 때문
*/
DListNode* dinsert(DListNode *before, const char *data) {
	DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
	strcpy(newnode->data, data);
	
	/* 
	문제(1)
	// 데이터가 할당된 newnode를 before 노드의 오른쪽에 삽입한다.	
	*/
	newnode->llink=before;
	newnode->rlink=before->rlink;
	before->rlink->llink=newnode;
	before->rlink=newnode;

	return newnode;
}

int main(void) {
	
	char navi;

	// 재생목록 생성
	DListNode* playlist = (DListNode *)malloc(sizeof(DListNode));
	init(playlist);
	
	// 재생목록 곡 삽입
	DListNode* last_insert; // 가장 최근에 삽입된 곡 (가장 최근에 삽입된 곡 뒤에 다른 곡을 삽입)
	last_insert = dinsert(playlist, "Golden");
	last_insert = dinsert(last_insert, "Soda Pop");
	last_insert = dinsert(last_insert, "뛰어(JUMP)");
	last_insert = dinsert(last_insert, "FAMOUS");
	last_insert = dinsert(last_insert, "Rich Man");
	last_insert = dinsert(last_insert, "XOXZ");

	DListNode *current; // 재생중인 곡 표시
	current = playlist->rlink; // 재생목록의 첫 곡부터 재생
	print_playlist(playlist, current);

	do {
		printf("\n원하는 곡을 탐색하여 재생하세요[이전곡(<), 다음곡(>), 재생종료(q)]: ");
		navi = getchar();
		if (navi == '<') {
			current = current->llink;
			if (current == playlist)
				current = current->llink;
		}
		else if (navi == '>') {
			current = current->rlink;
			if (current == playlist)
				current = current->rlink;
		}
		print_playlist(playlist, current);
		getchar();
	} while (navi != 'q');

}
