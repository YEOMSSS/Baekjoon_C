
// ������ �迭�� �̿��� ���ڿ��� �����ϰ� ���
// ���ÿ� ���� ���� �� �ٽ� ���

#include <stdio.h>

int main()
{
    int i;
    // ������ �迭 ���� �� �ʱ�ȭ
    char *ptrArray[4] = {{"Korea"}, {"bucheon"}, {"jibong-ro"}, {"43����"}};

    for (i = 0; i < 4; i++)
    {
        printf("\n %s", ptrArray[i]);
    }

    ptrArray[2] = "Jongro";
    printf("\n\n");
    for (i = 0; i < 4; i++)
    {
        printf("\n %s", ptrArray[i]);
    }
    return 0;
}