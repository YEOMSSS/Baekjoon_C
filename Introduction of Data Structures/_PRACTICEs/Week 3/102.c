
// ����ڿ��� �Է� ���� �������� 1���� �迭�� ���� ��, �迭 ������ ���

// #define _CRT_SECURE_WARNINGS
#include <stdio.h>

int main()
{
    int n;
    int multiply[9];

    printf(" 1~9�� ������ �Է��ϼ��� : ");

    // n�� ���� 1~9 ������ ���ڸ� �� �� �ֵ��� ���� ���� ����
    while (1) // True.
    {

        scanf("%d", &n);

        if (n <= 9)
            break;
        else // (n < 1 || n > 9)
            printf(" �ٽ� �Է��ϼ��� : ");
    }

    printf("\n");
    for (int i = 1; i < 10; i++)
    {
        multiply[i] = n * i; // ��� ���� �迭�� ����
        printf(" %d * %d = %d \n", n, i, multiply[i]);
    }
    return 0;
}