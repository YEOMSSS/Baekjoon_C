#include <stdio.h>

int main()
{
    int *ptr;
    int sale[2][2][4] =
        {{{63, 84, 140, 130}, {157, 209, 251, 312}}, {{59, 80, 130, 135}, {149, 187, 239, 310}}}; // 3차원 배열 생성 및 초기화

    ptr = &sale[0][0][0];
    // ptr = sale;

    for (int i = 0; i < 16; i++)
    {
        printf("\n address : %u    sale %d = %d", ptr, i, *ptr);
        ptr++;
    }

    printf("\n");
    return 0;
}