// ��� �Լ��� �̿��Ͽ� ���丮�� �� ���ϱ�

#include <stdio.h>

// ����ġ������ Ư���� �����Լ����� �Ʒ��� �Լ��� ���� �� ���, �Լ��� �������� �ʰ� ����.
long int fact(int); // �����Լ� ���� ���� ����

// �׳� �Լ� ��ü�� main������ �����ϸ� �Ǵ°� �ƴϾ�? �� ���� ������,
// �̰� �������� �� ������.

int main(void)
{
    int n, result;
    printf("\n ������ �Է��ϼ��� : ");
    scanf_s("%d", &n);

    result = fact(n);
    printf("\n\n %d�� ���丮�� ���� %d�Դϴ�. \n", n, result);

    return 0;
}

long int fact(int n)
{ // ���� ���� Ŀ�� �� �����Ƿ� int ���� ǥ�� ���� �� ū long int �ڷ����� ���
    int value;

    if (n <= 1) // �׳� n==1�̾ ������ �ʾ�?
    {           // ���� ����
        printf("\n fact(1) �Լ� ȣ��!");
        printf("\n fact(1) �� 1 ��ȯ");
        return 1;
    }
    else
    { // n�� 2�̻��� ��� else ������ ���� �ٽ� fact�Լ��� ȣ���Ѵ�
        printf("\n fact(%d) �Լ� ȣ��!", n);
        value = (n * fact(n - 1));
        printf("\n fact(%d) �� %d ��ȯ!", n, value);
        return value;
    }

    // ���� Ȯ���� ���� ȣ��� ��ȯ�� ����غ���.
}
