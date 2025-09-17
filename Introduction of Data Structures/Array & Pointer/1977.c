
// 완전제곱수 구하기

#include <stdio.h>

int main(void)
{
    int M, N;
    scanf("%d %d", &M, &N);

    int i = 1;
    // M 이상이 되는 i제곱 찾기
    while (i * i < M)
        i++;

    int sum = 0;
    int min = -1;
    while (i * i <= N)
    {
        // 첫 제곱수 저장
        if (min == -1)
            min = i * i;

        sum += i * i;
        i++;
    }

    if (min == -1)
        printf("%d\n", min);
    else
        printf("%d\n%d\n", sum, min);

    return 0;
}

// 근데 이게 왜 배열과 포인터냐
