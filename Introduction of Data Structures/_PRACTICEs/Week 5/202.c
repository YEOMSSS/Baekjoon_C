
// 정수 N을 받아 별산의 높이를 지정 한 후, 재귀 함수를 통해 별산을 출력

#include <stdio.h>

// recursion은 한 층을 출력하는 함수
void recursion(int finish, int start)
{
    // finish는 num의 값을 받는 매개변수,
    // start 는 최초의 값으로 설정된 매개변수

    // 원하는 층에 도달하면 종료
    if (finish == start)
    {
        for (int i = 0; i < start; i++)
        {
            printf("*");
        }
        printf("\n");

        return;
    }
    // 원하는 층에 도달하지 못했다면 재귀
    else
    {
        for (int i = 0; i < start; i++)
        {
            printf("*");
        }
        printf("\n");

        start++;
        recursion(finish, start);
    }
}

int main()
{

    int num;

    printf("별산의 높이를 입력하여 주세요! : ");
    scanf_s("%d", &num);

    recursion(num, 1);
}