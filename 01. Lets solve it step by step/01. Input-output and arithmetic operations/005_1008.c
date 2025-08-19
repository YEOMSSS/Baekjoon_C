#include <stdio.h>

int main() {

    double A, B;
    scanf("%lf %lf", &A, &B);

    printf("%.10lf", A / B);

    return 0;
}

// double은 float보다 큰 부동소수를 저장한다.
// float < double < long double
// int < long int < long long int의 float버전인 것이다.