
// �г⺰ ��� ����[������ ���]�� ���� 1���� �迭�� �����ϰ� �迭 ������ ���

#include <stdio.h>

int main(void)
{
	int score[3] = {91, 86, 74};	 // ũ�Ⱑ 3�� int �� �迭 �ʱ�ȭ
	char grade[3] = {'A', 'B', 'C'}; // ũ�Ⱑ 3�� char �� �迭 �ʱ�ȭ

	printf("\n *** �г⺰ ��� ���� *** \n\n");

	for (int i = 0; i < 3; i++)
	{
		printf("%d�г� : ���� = %d ��� = %c\n", i + 1, score[i], grade[i]);
	}
	return 0;
}