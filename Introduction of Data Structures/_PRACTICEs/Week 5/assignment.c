
#include <stdio.h>
#include <stdlib.h> // exit

void repeat_numbers(int num)
{
    if (num < 0)
    { // 음수 입력 확인 시 오류 판정, 즉시 프로그램 종료
        printf("입력받은 수가 자연수가 아닙니다.\n");
        exit(1);
    }

    int k = num % 10;

    if (num / 10 == 0)
    { // 기저 조건
        for (int i = 0; i < 10 - k; i++)
        {
            printf("%d", k);
        }
        printf("\n");
        return;
    }

    else
    {
        repeat_numbers(num / 10);

        for (int i = 0; i < 10 - k; i++)
        {
            printf("%d", k);
        }
        printf("\n");
    }
}

int main(void)
{
    int number;

    printf("number: ");
    scanf("%d", &number);
    repeat_numbers(number);

    return 0;
}