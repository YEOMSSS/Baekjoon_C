/* 포인터를 활용하여 문자열 처리하기*/

#include <stdio.h>

int main()
{
    int i;
    char string1[20] = "Dreams come true!";
    char string2[20];
    char *ptr1, *ptr2;

    ptr1 = string1;                                             // 시작주소 넣어주고
    printf("\n string1의 주소 = %d, ptr1 = %d", string1, ptr1); // 시작주소, 시작주소
    printf("\n string1 = %s \n ptr1 = %s", string1, ptr1);      // string1 \n string1
    // %s 는 문자열포인터를 받아 시작주소부터 \0을 만날 때까지 문자열을 출력한다.
    printf("\n\n %s", ptr1 + 7); // 7칸 옮긴값부터 출력
    ptr2 = &string1[7];          // 인덱스7주소 넣어주고
    printf("\n %s \n\n", ptr2);  // ptr1 + 7이랑 같은 값 출력
    for (i = 16; i >= 0; i--)
    {
        printf("%c", *(ptr1 + i)); // string1 거꾸로 출력
    }
    for (i = 0; i < 20; i++)
    {
        string2[i] = *(ptr1 + i); // string1 복사됨
    }

    printf("\n\n string1 = %s", string1); // string1
    printf("\n string2 = %s", string2);   // string1

    *ptr1 = 'P'; // 값 변경
    *(ptr1 + 1) = 'e';
    *(ptr1 + 2) = 'a';
    *(ptr1 + 3) = 'c';
    *(ptr1 + 4) = 'e';
    printf("\n\n string1 = %s\n", string1); // 0~4인덱스 변경됨

    return 0;
}
