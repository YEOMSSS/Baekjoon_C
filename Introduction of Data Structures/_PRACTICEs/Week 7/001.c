/*
어떤 수 n이 주어졌을 때, 재귀함수를 이용하여
1. n을 이진수로 나타내고
2. 해당 이진수의 0의 총 개수를 출력
*/

#include <stdio.h>

// n을 2진수로 출력하고, 0의 개수를 반환하는 재귀함수
int binary(int n)
{
    if (n == 0) // 굳이 n <= 0 일 필요가 있나?
    {
        return 0;
    }

    // 2로 나눴을 때 나머지는 A에 저장.
    int A = n % 2;
    int R = binary(n / 2);

    // 재귀함수 밑에 프린트가 있어서 높은 자리부터 출력된다.
    printf("%d", A);
    if (A == 0)
    {
        R += 1;
    }

    return R;
}

int main()
{
    int n;

    printf("양의 정수 n을 입력하시오 ");
    scanf_s("%d", &n);
    printf("%d을 이진수로 표현하면 ", n);

    // binary가 재귀를 돌면서 2진수를 출력해주고 0의 개수도 세준다.
    int result = binary(n);

    printf("\n%d 이진수의 0의 개수는 %d ", n, result);

    return 0;
}