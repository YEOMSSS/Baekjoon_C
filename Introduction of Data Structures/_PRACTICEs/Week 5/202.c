// ���� N�� �޾� ������ ���̸� ���� �� ��, ��� �Լ��� ���� ������ ���
#include <stdio.h>

void recursion(int finish, int start)
{
    // finish�� num�� ���� �޴� �Ű�����,
    // start �� ������ ������ ������ �Ű�����

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

    printf("������ ���̸� �Է��Ͽ� �ּ���! : ");
    scanf_s("%d", &num);

    recursion(num, 1);
}