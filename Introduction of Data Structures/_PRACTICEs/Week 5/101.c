#include <stdio.h>

// book�̶�� ����ü�� �����Ѵ�.
// �̸�, �۰�, ������ �����ϴ� ����ü�̴�.
struct book
{
    char title[50];
    char author[50];
    int price;
};

int main(void)
{
    // ����ü�� �ϳ� �����Ѵ�. �̸��� my_book
    struct book my_book = {
        "HTML�� CSS",
        "ȫ�浿",
        28000

    };
    // �ٸ� ����ü�� �ϳ� �� �����Ѵ�. �̸��� c_book
    struct book c_book = {
        "C�� ���� ���� �ڷᱸ�� ����",
        "������", 27000

    };

    printf("ù ��° å�� ������ %s�̰�, \n���ڴ� %s�̸�, \n������ %d���Դϴ�.\n\n", my_book.title, my_book.author, my_book.price);
    printf("�� ��° å�� ������ %s�̰�, \n���ڴ� %s�̸�, \n������ %d���Դϴ�.\n", c_book.title, c_book.author, c_book.price);

    return 0;
}