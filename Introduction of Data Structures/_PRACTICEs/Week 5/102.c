#include <stdio.h>

struct employee
{ //  employee��� ����ü ����
    char name[10];
    int year;
    int pay;
};

int main(void)
{

    int i;

    // ����ü �迭�� ����ϱ�
    // ���� ����ü�� �� ���� �ٷ� �� �ֱ� ������ �ڵ尡 ���������.
    struct employee Lee[4] = {
        {"����ȣ", 2014, 4200},
        {"���ѿ�", 2015, 3300},
        {"�̻��", 2015, 3500},
        {"�̻��", 2016, 2900}

    };

    // for������ ����ü �迭�� �Ҵ��� ����Ѵ�. Lee[i].�� ����
    // ����ü 4������Ÿ� for�� �ѹ濡 �о���ȴ�.
    for (i = 0; i < 4; i++)
    {
        // 3�ٷ� ���� �ᵵ �ȴ�.
        printf("�̸� : %s\n�Ի� : %d\n���� : %d\n\n", Lee[i].name, Lee[i].year, Lee[i].pay);
    }

    return 0;
}