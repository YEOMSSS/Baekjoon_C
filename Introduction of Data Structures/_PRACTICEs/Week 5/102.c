#include <stdio.h>

struct employee
{ //  employee라는 구조체 생성
    char name[10];
    int year;
    int pay;
};

int main(void)
{

    int i;

    // 구조체 배열로 사용하기
    // 여러 구조체를 한 번에 다룰 수 있기 때문에 코드가 깔끔해진다.
    struct employee Lee[4] = {
        {"이진호", 2014, 4200},
        {"이한영", 2015, 3300},
        {"이상원", 2015, 3500},
        {"이상범", 2016, 2900}

    };

    // for문으로 구조체 배열을 할당해 출력한다. Lee[i].의 형태
    // 구조체 4개만들거를 for문 한방에 털어버렸다.
    for (i = 0; i < 4; i++)
    {
        // 3줄로 나눠 써도 된다.
        printf("이름 : %s\n입사 : %d\n연봉 : %d\n\n", Lee[i].name, Lee[i].year, Lee[i].pay);
    }

    return 0;
}