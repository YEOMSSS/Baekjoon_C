
#include <stdio.h>
#include <string.h> // strcpy

struct employee
{ //  employee��� ����ü ����
    char name[10];
    int year;
    int pay;
};

int main(void)
{

    struct employee Lee;
    // ȭ��ǥ������ ����� ���� ����ü ������ ����
    struct employee *Sptr = &Lee;

    // ���ڹ迭 �Ҵ�� strcpy ���
    strcpy(Sptr->name, "�̼���");
    Sptr->year = 2015;
    Sptr->pay = 5900;

    printf("�̸� : %s\n", Sptr->name);
    printf("�Ի� : %d\n", Sptr->year);
    printf("���� : %d\n", Sptr->pay);

    return 0;
}
