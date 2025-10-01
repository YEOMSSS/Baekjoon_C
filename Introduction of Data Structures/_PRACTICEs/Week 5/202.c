// 정수 N을 받아 별산의 높이를 지정 한 후, 재귀 함수를 통해 별산을 출력
#include <stdio.h>

void recursion(int finish, int start)
{
    // finish는 num의 값을 받는 매개변수,
    // start 는 최초의 값으로 설정된 매개변수

    if (finish == start)
    {
        for (int i = 0; i < start; i++)
        {
            printf("*");
        }
        printf("\n");
        return;
    }
    else
    {
        for (int i = 0; i < start; i++)
        {
            printf("*");
        }
        printf("\n");

        recursion(finish, start + 1);
    }
}

int main()
{

    int num;

    printf("별산의 높이를 입력하여 주세요! : ");
    scanf_s("%d", &num);

    recursion(num, 1);
}