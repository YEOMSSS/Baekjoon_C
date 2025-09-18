
// ���� �ڵ��� ����� ������ ������.

#include <stdio.h>

int main()
{
    int i = 10, j = 20; // ���� ����.
    int *ptr;           // ������ ����.

    printf("\n i�� �� = %d \n j�� �� = %d", i, j); // 10, 20
    printf("\n i�� �޸� �ּ�(&i) = %u", &i);     // &i
    printf("\n j�� �޸� �ּ�(&j) = %u", &j);     // &j

    ptr = &i; // ������ ������ ���� ����

    printf("\n\n << ptr=&i ���� >>");
    printf("\n ptr�� �޸� �ּ�(&ptr) = %u", &ptr); // &ptr
    printf("\n ptr�� ��(ptr) = %u", ptr);            // &i
    printf("\n ptr�� ���� ��(*ptr) = %d", *ptr);     // 10

    ptr = &j; // ������ ������ ���� �缳��

    printf("\n\n << ptr=&j ���� >>");
    printf("\n ptr�� �޸� �ּ�(&ptr) = %u", &ptr); // &ptr
    printf("\n ptr�� ��(ptr) = %u", ptr);            // &j
    printf("\n ptr�� ���� ��(*ptr) = %d", *ptr);     // 20

    i = *ptr;
    printf("\n\n << i=*ptr ���� >>");
    printf("\n i�� �� = %d", i); // 20

    return 0;
}

// %u �̰� �������ǰ�? %p�� �ּ� format���ε�..
// %u�� ���� ��ȣ���� 10�������� �����ּҵ� Ŀ���� �ȴٰ�.
// �׸��� ��� ������ �� �ٸ���. %p�� ��¥ �ּҸ� ��´�. 10������ �ƴ�.