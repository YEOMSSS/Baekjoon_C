#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main(void)
{
    int N;
    scanf("%d", &N);

    int arr[N];

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    int height = 0;
    int result = 0;
    for (int i = 1; i < N; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            if (height == -1)
                height = 0;

            height += arr[i] - arr[i - 1];
        }
        else
        {
            result = max(result, height);
            height = -1;
        }
    }

    result = max(result, height);
    printf("%d", result);

    return 0;
}