// 재귀 함수를 이용하여 팩토리얼 값 구하기

#include <stdio.h>

// 절자치향언어의 특성상 메인함수보다 아래에 함수를 생성 할 경우, 함수를 실행하지 않고 종료.
long int fact(int); // 메인함수 위에 먼저 선언

// 그냥 함수 자체를 main위에서 선언하면 되는거 아니야? 할 수도 있지만,
// 이게 가독성이 좀 괜찮다.

int main(void)
{
    int n, result;
    printf("\n 정수를 입력하세요 : ");
    scanf_s("%d", &n);

    result = fact(n);
    printf("\n\n %d의 팩토리얼 값은 %d입니다. \n", n, result);

    return 0;
}

long int fact(int n)
{ // 연산 값이 커질 수 있으므로 int 보다 표현 값이 더 큰 long int 자료형을 사용
    int value;

    if (n <= 1) // 그냥 n==1이어도 괜찮지 않아?
    {           // 기저 조건
        printf("\n fact(1) 함수 호출!");
        printf("\n fact(1) 값 1 반환");
        return 1;
    }
    else
    { // n이 2이상일 경우 else 문으로 들어와 다시 fact함수를 호출한다
        printf("\n fact(%d) 함수 호출!", n);
        value = (n * fact(n - 1));
        printf("\n fact(%d) 값 %d 반환!", n, value);
        return value;
    }

    // 과정 확인을 위해 호출과 반환을 출력해보자.
}
