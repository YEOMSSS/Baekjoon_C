
// ����ڿ��� ���ڿ��� �Է� �޾� �迭�� �����ϰ� ���.
// �׸���, ���ڿ��� ���̸� ����Ͽ� ���

#include <stdio.h>

// int main(void)
// {

//     char arr[50];
//     scanf("%50s", arr);

//     printf("%s", arr);
//     return 0;
// }

#include <stdio.h>

int main()
{
    int length = 0;
    char str[50]; // char ��, ũ�Ⱑ 50�� �迭 ����

    printf("\n ���ڿ��� �Է��ϼ��� : ");
    // scanf_s�� sizeof�� ���ڿ��� �޾ƾ� �Ѵ�? scanf�� �ʿ������?
    scanf_s("%s", str, sizeof(str));

    printf("\n �Էµ� ���ڿ��� \"");
    for (int i = 0; str[i]; i++)
    { // ������ ���� \0 ���� ����, \0 ���� �������� �� �ݺ����� �����
        printf("%c", str[i]);
        length += 1;
    }
    printf("\"�Դϴ�.");
    printf("\n\n �Էµ� ���ڿ��� ���� = %d �Դϴ�.\n", length);

    return 0;
}