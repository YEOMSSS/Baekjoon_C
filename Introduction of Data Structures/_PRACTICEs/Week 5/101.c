#include <stdio.h>

// book이라는 구조체를 생성한다.
// 이름, 작가, 가격을 저장하는 구조체이다.
struct book
{
    char title[50];
    char author[50];
    int price;
};

int main(void)
{
    // 구조체를 하나 생성한다. 이름은 my_book
    struct book my_book = {
        "HTML과 CSS",
        "홍길동",
        28000

    };
    // 다른 구조체를 하나 더 생성한다. 이름은 c_book
    struct book c_book = {
        "C로 배우는 쉬운 자료구조 기초",
        "이지영", 27000

    };

    printf("첫 번째 책의 제목은 %s이고, \n저자는 %s이며, \n가격은 %d원입니다.\n\n", my_book.title, my_book.author, my_book.price);
    printf("두 번째 책의 제목은 %s이고, \n저자는 %s이며, \n가격은 %d원입니다.\n", c_book.title, c_book.author, c_book.price);

    return 0;
}