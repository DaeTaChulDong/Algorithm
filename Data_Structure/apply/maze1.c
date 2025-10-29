#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAZE_SIZE 6
char maze[MAZE_SIZE][MAZE_SIZE]={ //0은 갈 수 있는, 1은 막힌 미로 구조
    {'1','1','1','1','1','1'},
    {'e','0','0','0','1','1'},//e:입구
    {'1','1','1','0','1','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','x','1'},//x:출구
    {'1','1','1','1','1','1'},
};

typedef struct{ //행렬을 스택에 저장
    short r; //행
    short c; //열
}   element;

#define MAX_STACK_SIZE 100
typedef struct{
    element data[MAX_STACK_SIZE];
    int top;
}   StackType;

void push_loc(StackType *s, int r, int c){ //좌표저장, r,c:방문하려고 하는 좌표
    if(r<0 || c<0) return;
    if (maze[r][c]!='1' && maze[r][c]!='.'){ //1:막힌곳, .:이미 방문한 곳도 저장하면 안됨
        element tmp;
        tmp.r=r;
        tmp.c=c;
        push(s,tmp); //막힌곳도 방문한곳도 아닐 때에만 push해서 스택에 넣어줌
    }
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]){
    printf("\n");
    for(int r=0;r<MAZE_SIZE; r++){
        for(int c=0; c<MAZE_SIZE; c++){
            printf("%c", maze[r][c]);
        }
        printf("\n");
    }
}

int main(void){
    int r,c;
    StackType s;

    element entry={1,0};
    element here;

    here=entry;
    init_stack(&s);

    while (maze[here.r][here.c]!='x'){ //현재위치가 출구가 아니라면
        r=here.r;
        c=here.c;
        maze[r][c]='.'; //방문한위치 .으로 표시
        maze_print(maze);

        push_loc(&s,r-1,c); //이 설정에 따라 버전이 나뉠 수 있는 주요 알고리즘
        push_loc(&s,r+1,c);
        push_loc(&s,r,c-1);
        push_loc(&s,r,c+1);
        //!!스택 삽입순서-방문 우선순위와 정반대
        if(is_empty(&s)){
            printf("실패\n");
            return 1;
        }
        else
            here=pop(&s);
    }
    printf("성공\n");
    return 0;
}