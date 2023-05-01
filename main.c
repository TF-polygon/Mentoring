#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_score(int student[][3], int size) {
	for (int i = 0; i < 3; i++) {
		printf("%d 과목 점수 : ", i + 1);
		for (int j = 0; j < size; j++) {
			printf("%d ", student[j][i]);
		}
		printf("\n");
	}
}
void print_minMax(int student[][3], int size) {
	int min;
	int max;
	for (int i = 0; i < 3; i++) {
		min = student[0][i];
		max = student[0][i];
		for (int j = 0; j < size; j++) {
			if (max < student[j][i]) {
				max = student[j][i];
			}
			if (min > student[j][i]) {
				min = student[j][i];
			}
		}
		printf("%d 과목의 최솟값, 최댓값 : %d %d\n", i + 1, min, max);
	}
}
int main(void) {
	int student[20][3];
	int size;
	int i, j;
	while (1) {
		printf("학생 수를 입력 하세요: ");
		scanf("%d", &size);
		if (size >= 1 || size <= 20) {
			break;
		}
		else {
			printf("제시된 조건에 부합하지 않습니다. 다시 입력하십시오.\n");
		}
	}
	for (i = 0; i < size; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d번 학생의 %d 과목 점수 : ", i + 1, j + 1);
			scanf("%d", &student[i][j]);
			if (student[i][j] < 0 || student[i][j] > 100) {
				printf("제시된 조건에 부합하지 않습니다. 다시 입력하십시오.\n");
				j--;
			}
		}
	}
	print_score(student, size);
	print_minMax(student, size);
	return 0;
}