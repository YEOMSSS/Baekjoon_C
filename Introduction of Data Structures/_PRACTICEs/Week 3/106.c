
// ����ڿ��� �л� �� ���� �̸�, �а�, �й��� �Է� �޾� 3���� ���� �迭�� �����ϰ�, �迭 ������ ���

#include <stdio.h>

int main()
{
    // �л� ��, �Է¹��� Ƚ��, ���ڿ� ����
    char student[2][3][20];

    for (int i = 0; i < 2; i++)
    {
        printf(" �л� %d�� �̸� : ", i + 1);
        gets(student[i][0]);
        // scanf("%s", student[i][0]);
        printf(" �л� %d�� �а� : ", i + 1);
        gets(student[i][1]);
        // scanf("%s", student[i][1]);
        printf(" �л� %d�� �й� : ", i + 1);
        gets(student[i][2]);
        // scanf("%s", student[i][2]);
    }
    for (int i = 0; i < 2; i++)
    {
        printf("\n\n �л� %d", i + 1);
        for (int j = 0; j < 3; j++)
        {
            printf("\n\t"); // \t�� tab�� ���� ������ ��µȴ�.
            // != \0�� ������ �����ϴٴ°�.
            // for (int k = 0; student[i][j][k] != '\0'; k++)
            for (int k = 0; student[i][j][k]; k++)
                printf("%c", student[i][j][k]);
        }
    }
    return 0;
}

// gets �̰� �ᵵ �Ǵ°� �¾�?
// fgets(student[i][0], sizeof(student[i][0]), stdin);
// student[i][0][strlen(student[i][0]) - 1] = '\0';