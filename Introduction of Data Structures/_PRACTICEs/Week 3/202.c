
// 포인터 배열을 이용해 문자열을 저장하고 출력
// 예시와 같이 수정 후 다시 출력

#include <stdio.h>

int main()
{
    int i;
    // 포인터 배열 선언 및 초기화
    char *ptrArray[4] = {{"Korea"}, {"bucheon"}, {"jibong-ro"}, {"43번지"}};

    for (i = 0; i < 4; i++)
    {
        printf("\n %s", ptrArray[i]);
    }

    ptrArray[2] = "Jongro";
    printf("\n\n");
    for (i = 0; i < 4; i++)
    {
        printf("\n %s", ptrArray[i]);
    }
    return 0;
}