
// ���� �迭�� ���ڿ��� �����ϰ� ���

#include <stdio.h>

int main(void)
{
    // ũ�Ⱑ 20�� ������ �迭 ���� �� �ʱ�ȭ
    char str[20] = "Data Structure!";

    printf("\n ���� �迭 str[] : ");

    // for (int i = 0; i < 20; i++)
    // ���ǽ��� str�� ���� \0�� �ƴ� ������.
    // �̷��� ���ǽĿ� str[i] �־������ \0 �������� �ݺ�.
    for (int i = 0; str[i]; i++)
        printf("%c", str[i]);

    printf("\n");
    return 0;
}