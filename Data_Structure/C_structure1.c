//구조체 선언 방법1: 태그 사용
struct stdstr{
    char name[10];
    int age;
    double gpa;
};
struct stdstr std1;
// stdstr->구조체 태그, struct stdstr->구조체 타입, std1->구조체 변수명

//구조체 선언 방법2: 태그+typedef 별칭
typedef struct stdstr{
    char name[10];
    int age;
    double gpa;
} student;
student std2;
// stdstr->구조체 태그, student->typedef 별칭
// struct stdstr==student->구조체 타입, std2->구조체 변수명
// struct stdstr std2;도 사용할 수 있다.

//구조체 선언 방법3: 익명 구조체+typedef별칭
typedef struct{
    char name[10];
    int age;
    double gpa;
}   student;
student std3;
// student->typedef 별칭, std3->구조체 변수명

//구조체 선언 방법4: 익명 구조체+곧바로 변수 선언
struct{
    char name[10];
    int age;
    double gpa;
}   student; //student->구조체 변수명
//student std4;하게 되면 에러 발생!