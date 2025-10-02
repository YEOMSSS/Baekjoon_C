#include <stdio.h>

int main() {

    int A, B;
    scanf("%d%d", &A, &B);

    printf("%d\n%d\n%d\n%d\n%d", A + B, A - B, A * B, A / B, A % B);

    return 0;
}

// 합, 차, 곱, 몫, 나머지.
// 그냥 /로 계산했지만 %d로 출력되기 때문에 뒤는 알아서 잘린다.