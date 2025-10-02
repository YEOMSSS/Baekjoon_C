
#include <stdio.h>
#include <stdlib.h> // exit

void repeat_numbers(int num)
{
    if (num < 0)
    { // ���� �Է� Ȯ�� �� ���� ����, ��� ���α׷� ����
        printf("�Է¹��� ���� �ڿ����� �ƴմϴ�.\n");
        exit(1);
    }

    int k = num % 10;

    if (num / 10 == 0)
    { // ���� ����
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