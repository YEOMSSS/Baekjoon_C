#include <stdio.h>

int main(void)
{
    int N, P;
    scanf("%d %d", &N, &P);

    int arr[P];
    for (int i = 0; i < P; i++)
        arr[i] = 0;

    int temp = N;
    int result = 0;
    while (1)
    {
        temp = temp * N % P;

        // 사이클 원소의 수였구나? ;;;
        if (arr[temp] == 1)
            result += 1;

        if (arr[temp] == 2)
            break;

        arr[temp] += 1;
    }

    printf("%d", result);
    return 0;
}