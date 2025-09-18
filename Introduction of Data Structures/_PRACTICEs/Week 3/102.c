
// 사용자에게 입력 받은 구구단을 1차원 배열에 저장 후, 배열 내용을 출력

// #define _CRT_SECURE_WARNINGS
#include <stdio.h>

int main()
{
    int n;
    int multiply[9];

    printf(" 1~9의 정수를 입력하세요 : ");

    // n의 값이 1~9 사이의 숫자만 들어갈 수 있도록 무한 루프 설정
    while (1) // True.
    {

        scanf("%d", &n);

        if (n <= 9)
            break;
        else // (n < 1 || n > 9)
            printf(" 다시 입력하세요 : ");
    }

    printf("\n");
    for (int i = 1; i < 10; i++)
    {
        multiply[i] = n * i; // 계산 값을 배열에 저장
        printf(" %d * %d = %d \n", n, i, multiply[i]);
    }
    return 0;
}