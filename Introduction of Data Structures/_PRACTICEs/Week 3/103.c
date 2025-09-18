
// 문자 배열에 문자열을 저장하고 출력

#include <stdio.h>

int main(void)
{
    // 크기가 20인 문자형 배열 선언 및 초기화
    char str[20] = "Data Structure!";

    printf("\n 문자 배열 str[] : ");

    // for (int i = 0; i < 20; i++)
    // 조건식은 str의 값이 \0이 아닐 때까지.
    // 이렇게 조건식에 str[i] 넣어버리면 \0 볼때까지 반복.
    for (int i = 0; str[i]; i++)
        printf("%c", str[i]);

    printf("\n");
    return 0;
}