
// 3차원 배열에 값을 저장하고 배열 내용을 출력

#include <stdio.h>

int main()
{
    // 3차원 배열 생성
    int array[2][3][4];

    // 순서용 변수
    int value = 1;

    // 3차원 배열이니까 3중포문으로 풀어 출력
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                array[i][j][k] = value;
                printf("\n array[%d][%d][%d] = %d", i, j, k, array[i][j][k]);
                value++;
            }
        }
    }

    return 0;
}
