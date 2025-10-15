// 다항식의 덧셈 연산 실습

#include <stdio.h>

#define MAX(a, b) ((a > b) ? a : b) // a,b 비교후 더 큰 값을 가지는 매크로 MAX(a,b)를 정의
#define MAX_DEGREE 50               // MAX_DEGREE의 값을 50으로 정의

// 구조체 polynomial 정의. 차수와 계수배열이 저장됨
typedef struct
{
    // 차수
    int degree;
    // 계수
    float coef[MAX_DEGREE];

} polynomial;

// 함수 뒤에 만들거임. 미리 정의 한번 해주자.
polynomial addPoly(polynomial, polynomial);
void printPoly(polynomial);

int main()
{
    polynomial A = {3, {4, 3, 5, 0}};
    polynomial B = {4, {3, 1, 0, 2, 1}};
    polynomial C;
    C = addPoly(A, B);

    printf("\n A(x) =");
    printPoly(A);
    printf("\n B(x) =");
    printPoly(B);
    printf("\n C(x) =");
    printPoly(C);

    return 0;
}

// poly A, B를 입력받으면 둘이 더해진 형태의 poly를 반환하는 함수 addPoly
// 반환형이 polynomial이다. 그래서 polynomial addPoly().
polynomial addPoly(polynomial A, polynomial B)
{
    // A, B가 더해질 polynomial C를 만든다.
    polynomial C;

    // N_index는 현재까지 처리한 계수 개수 & while문 탈출 조건
    int A_index = 0, B_index = 0, C_index = 0;

    // N_dgree는 현재 각 다항식의 사용해야 하는 위치 표시
    int A_degree = A.degree, B_degree = B.degree;
    C.degree = MAX(A.degree, B.degree); // A, B의 차수 중 큰것이 C의 차수

    // 동일한 지수의 계수끼리 더해서 C.coef에 반환하자.
    // 사용한 차수 깎아주고, 인덱스는 한칸 앞으로.

    // degree + 1 = 가진 계수 정보의 개수.
    // degree < index가 되면 모든 계수를 처리했다는 뜻이므로, while문 탈출조건으로 활용가능
    while (A_index <= A.degree && B_index <= B.degree)
    {
        // A와 B의 지수가 같을 때 항끼리 더해준다.
        if (A_degree == B_degree)
        {
            C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
            A_degree--;
            B_degree--;
            // A_index++; 이런 것들을 밑에 또 써줄 거 없이 coef에 넣으면서 동시에 후연산 조져준다.
        }
        // A가 B보다 현재 지수가 클 때
        else if (A_degree > B_degree)
        {
            C.coef[C_index++] = A.coef[A_index++];
            A_degree--;
        }
        // B가 A보다 현재 지수가 클 때
        else // (A_degree < B_degree)
        {
            C.coef[C_index++] = B.coef[B_index++];
            B_degree--;
        }
    }

    return C;
}

void printPoly(polynomial P)
{
    int i, degree;
    degree = P.degree;

    for (i = 0; i <= P.degree; i++)
    {
        printf("%3.0f x ^%d", P.coef[i], degree--);
        if (i < P.degree)
            printf(" +");
    }
    printf("\n");
}
