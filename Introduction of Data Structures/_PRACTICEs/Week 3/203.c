/* �����͸� Ȱ���Ͽ� ���ڿ� ó���ϱ�*/

#include <stdio.h>

int main()
{
    int i;
    char string1[20] = "Dreams come true!";
    char string2[20];
    char *ptr1, *ptr2;

    ptr1 = string1;                                             // �����ּ� �־��ְ�
    printf("\n string1�� �ּ� = %d, ptr1 = %d", string1, ptr1); // �����ּ�, �����ּ�
    printf("\n string1 = %s \n ptr1 = %s", string1, ptr1);      // string1 \n string1
    // %s �� ���ڿ������͸� �޾� �����ּҺ��� \0�� ���� ������ ���ڿ��� ����Ѵ�.
    printf("\n\n %s", ptr1 + 7); // 7ĭ �ű䰪���� ���
    ptr2 = &string1[7];          // �ε���7�ּ� �־��ְ�
    printf("\n %s \n\n", ptr2);  // ptr1 + 7�̶� ���� �� ���
    for (i = 16; i >= 0; i--)
    {
        printf("%c", *(ptr1 + i)); // string1 �Ųٷ� ���
    }
    for (i = 0; i < 20; i++)
    {
        string2[i] = *(ptr1 + i); // string1 �����
    }

    printf("\n\n string1 = %s", string1); // string1
    printf("\n string2 = %s", string2);   // string1

    *ptr1 = 'P'; // �� ����
    *(ptr1 + 1) = 'e';
    *(ptr1 + 2) = 'a';
    *(ptr1 + 3) = 'c';
    *(ptr1 + 4) = 'e';
    printf("\n\n string1 = %s\n", string1); // 0~4�ε��� �����

    return 0;
}
