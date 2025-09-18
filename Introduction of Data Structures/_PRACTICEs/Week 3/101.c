
// 학년별 취득 학점[총점과 등급]을 각각 1차원 배열에 저장하고 배열 내용을 출력

#include <stdio.h>

int main(void)
{
	int score[3] = {91, 86, 74};	 // 크기가 3인 int 형 배열 초기화
	char grade[3] = {'A', 'B', 'C'}; // 크기가 3인 char 형 배열 초기화

	printf("\n *** 학년별 취득 학점 *** \n\n");

	for (int i = 0; i < 3; i++)
	{
		printf("%d학년 : 총점 = %d 등급 = %c\n", i + 1, score[i], grade[i]);
	}
	return 0;
}