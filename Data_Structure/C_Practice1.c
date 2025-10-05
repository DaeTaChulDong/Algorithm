//구조체 기본 틀
struct studentTag{
    char name[10];
    int age;
    double gpa;
};

//구조체 변수 s 생성, 값 할당
struct studentTag s;
strcpy(s.name, "kim");
s.age=20;
s.gpa=4.3;