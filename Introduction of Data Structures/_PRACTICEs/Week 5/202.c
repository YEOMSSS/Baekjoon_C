
// ���� N�� �޾� ������ ���̸� ���� �� ��, ��� �Լ��� ���� ������ ���

#include <stdio.h>

// recursion�� �� ���� ����ϴ� �Լ�
void recursion(int finish, int start)
{
    // finish�� num�� ���� �޴� �Ű�����,
    // start �� ������ ������ ������ �Ű�����

    // ���ϴ� ���� �����ϸ� ����
    if (finish == start)
    {
        for (int i = 0; i < start; i++)
        {
            printf("*");
        }
        printf("\n");

        return;
    }
    // ���ϴ� ���� �������� ���ߴٸ� ���
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

    printf("������ ���̸� �Է��Ͽ� �ּ���! : ");
    scanf_s("%d", &num);

    recursion(num, 1);
}