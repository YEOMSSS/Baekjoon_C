/*
#include <stdio.h>

int cnt_0 = 0, cnt_1 = 0;

int fibonacci(int n)
{
    if (n == 0)
    {
        cnt_0 += 1;
        return 0;
    }
    else if (n == 1)
    {
        cnt_1 += 1;
        return 1;
    }
    else
        return (fibonacci(n - 1) + fibonacci(n - 2));
}

int main(void)
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N);
        fibonacci(N);

        printf("%d %d\n", cnt_0, cnt_1);

        cnt_0 = 0;
        cnt_1 = 0;
    }
    return 0;
}
*/

// 뭐, 원리는 이런 느낌이지만 시간초과 나니까 dp로 풀자.

#include <stdio.h>

void func(int N)
{
    if (N == 0)
    {
        printf("1 0\n");
        return;
    }

    long long arr[N + 1];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    printf("%lld %lld\n", arr[N - 1], arr[N]);
}

int main(void)
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N);
        func(N);
    }
    return 0;
}