// (ptr + i) == (&sale[0][0] + i) == sale배열에 저장된 i번째 데이터의 주소
// *(ptr + i) == (&sale[0][0] + i) == sale배열에 저장된 i번째 데이터의 값

// 2차원 배열의 경우
#include <stdio.h>

int main()
{

    int *ptr; // ptr에 주소가 저장되고, *ptr은 ptr이 가리키는 값을 나타냄
    int sale[2][4] = {{63, 84, 140, 130}, {157, 209, 251, 312}};
    // 2차원 배열 생성 및 초기화
    ptr = &sale[0][0]; // ptr = sale

    for (int i = 0; i < 8; i++)
    {
        printf("\n address : %u sale %d = %d", ptr, i, *ptr);
        ptr++; // 인덱스 넘어가기
    }

    printf("\n");
    return 0;
}