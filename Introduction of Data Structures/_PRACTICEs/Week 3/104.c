
// 사용자에게 문자열을 입력 받아 배열로 저장하고 출력.
// 그리고, 문자열의 길이를 계산하여 출력

#include <stdio.h>

// int main(void)
// {

//     char arr[50];
//     scanf("%50s", arr);

//     printf("%s", arr);
//     return 0;
// }

#include <stdio.h>

int main()
{
    int length = 0;
    char str[50]; // char 형, 크기가 50인 배열 선언

    printf("\n 문자열을 입력하세요 : ");
    // scanf_s는 sizeof로 문자열을 받아야 한다? scanf는 필요없던데?
    scanf_s("%s", str, sizeof(str));

    printf("\n 입력된 문자열은 \"");
    for (int i = 0; str[i]; i++)
    { // 문장의 끝에 \0 값이 들어가며, \0 값에 도달했을 때 반복문을 멈춘다
        printf("%c", str[i]);
        length += 1;
    }
    printf("\"입니다.");
    printf("\n\n 입력된 문자열의 길이 = %d 입니다.\n", length);

    return 0;
}