
#include <stdio.h>
#include <string.h> // strcpy

struct employee
{ //  employee라는 구조체 생성
    char name[10];
    int year;
    int pay;
};

int main(void)
{

    struct employee Lee;
    // 화살표연산자 사용을 위해 구조체 포인터 선언
    struct employee *Sptr = &Lee;

    // 문자배열 할당시 strcpy 사용
    strcpy(Sptr->name, "이순신");
    Sptr->year = 2015;
    Sptr->pay = 5900;

    printf("이름 : %s\n", Sptr->name);
    printf("입사 : %d\n", Sptr->year);
    printf("연봉 : %d\n", Sptr->pay);

    return 0;
}
