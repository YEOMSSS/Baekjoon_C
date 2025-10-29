#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int T;
    if (scanf("%d", &T) != 1)
        return 0;

    while (T--)
    {
        int M, N;
        scanf("%d %d", &M, &N);

        int *arr = (int *)malloc(sizeof(int) * N * M);
        if (!arr)
            return 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf("%d", &arr[i * M + j]);

        __int128 biggest = 0;
        int result = 0;

        for (int j = 0; j < M; j++)
        {
            __int128 mult = 1;
            for (int i = 0; i < N; i++)
                mult *= arr[i * M + j];

            if (j == 0)
            {
                biggest = mult; // 파이썬과 동일한 초기화
                continue;
            }
            if (biggest <= mult)
            { // 동률이면 뒤 열 선택
                biggest = mult;
                result = j;
            }
        }

        printf("%d\n", result + 1);
        free(arr);
    }
    return 0;
}
