
// 다음 코드의 결과를 유추해 보세요.

#include <stdio.h>

int main()
{
    int i = 10, j = 20; // 변수 선언.
    int *ptr;           // 포인터 선언.

    printf("\n i의 값 = %d \n j의 값 = %d", i, j); // 10, 20
    printf("\n i의 메모리 주소(&i) = %u", &i);     // &i
    printf("\n j의 메모리 주소(&j) = %u", &j);     // &j

    ptr = &i; // 포인터 변수의 값을 설정

    printf("\n\n << ptr=&i 실행 >>");
    printf("\n ptr의 메모리 주소(&ptr) = %u", &ptr); // &ptr
    printf("\n ptr의 값(ptr) = %u", ptr);            // &i
    printf("\n ptr의 참조 값(*ptr) = %d", *ptr);     // 10

    ptr = &j; // 포인터 변수의 값을 재설정

    printf("\n\n << ptr=&j 실행 >>");
    printf("\n ptr의 메모리 주소(&ptr) = %u", &ptr); // &ptr
    printf("\n ptr의 값(ptr) = %u", ptr);            // &j
    printf("\n ptr의 참조 값(*ptr) = %d", *ptr);     // 20

    i = *ptr;
    printf("\n\n << i=*ptr 실행 >>");
    printf("\n i의 값 = %d", i); // 20

    return 0;
}

// %u 이게 괜찮은건가? %p가 주소 format형인데..
// %u를 쓰면 부호없는 10진수여서 음수주소도 커버가 된다고.
// 그리고 출력 형식이 좀 다르네. %p는 진짜 주소를 뱉는다. 10진수가 아님.