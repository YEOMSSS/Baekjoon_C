
#include <stdio.h>

int main(void)
{

    int N;
    scanf("%d", &N);

    int arr[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    int combo = arr[0];
    int total = arr[0];

    for (int i = 1; i < N; i++)
    {
        if (!arr[i])
            combo = 0;
        else if (arr[i])
            combo++;

        if (combo)
            total += combo;
    }

    printf("%d", total);

    return 0;
}