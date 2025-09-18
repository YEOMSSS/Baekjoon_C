
// 사용자에게 학생 두 명의 이름, 학과, 학번을 입력 받아 3차원 문자 배열에 저장하고, 배열 내용을 출력

#include <stdio.h>

int main()
{
    // 학생 수, 입력받을 횟수, 문자열 길이
    char student[2][3][20];

    for (int i = 0; i < 2; i++)
    {
        printf(" 학생 %d의 이름 : ", i + 1);
        gets(student[i][0]);
        // scanf("%s", student[i][0]);
        printf(" 학생 %d의 학과 : ", i + 1);
        gets(student[i][1]);
        // scanf("%s", student[i][1]);
        printf(" 학생 %d의 학번 : ", i + 1);
        gets(student[i][2]);
        // scanf("%s", student[i][2]);
    }
    for (int i = 0; i < 2; i++)
    {
        printf("\n\n 학생 %d", i + 1);
        for (int j = 0; j < 3; j++)
        {
            printf("\n\t"); // \t는 tab을 누른 것으로 출력된다.
            // != \0은 생략이 가능하다는거.
            // for (int k = 0; student[i][j][k] != '\0'; k++)
            for (int k = 0; student[i][j][k]; k++)
                printf("%c", student[i][j][k]);
        }
    }
    return 0;
}

// gets 이거 써도 되는거 맞어?
// fgets(student[i][0], sizeof(student[i][0]), stdin);
// student[i][0][strlen(student[i][0]) - 1] = '\0';