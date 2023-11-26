/*		date : 2023-08-01
*		name : Tae Min
*		program : Minimun cost
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_COL 3
#define MAX_ROW 3

void initialize(int min[MAX_ROW][MAX_COL]);
int FindMinCost(int cost[MAX_ROW][MAX_COL], int row, int col);
int Min(int x, int y, int z);
void print(int arr[MAX_ROW][MAX_COL]);


int memo[MAX_ROW][MAX_COL];

void main() {
	int cost[MAX_ROW][MAX_COL];
	initialize(cost);
	print(cost);
	printf("  %d  \n\n", FindMinCost(cost, 2, 2));
	print(memo);
}

int FindMinCost(int cost[MAX_ROW][MAX_COL], int row, int col) { // �ּ� ����� ã�� 

	if (row < 0 || col < 0)
		return INT_MAX;
	// ���� index ���� �ܿ��� �ִ� int ���� ��ȯ�ؼ� �ش� index�� �ּҰ��� �ǵ��� �Ѵ�.
	else if (row == 0 && col == 0) {
		memo[0][0] = cost[0][0];
		return cost[0][0];
	}
	// memo�� �̹� ���� ����ִٸ� �� ���� ��ȯ�Ѵ�.
	if (memo[row][col] != -1)
		return memo[row][col];
	
	memo[row][col] = cost[row][col] + Min(FindMinCost(cost, row - 1, col - 1), FindMinCost(cost, row - 1, col), FindMinCost(cost, row, col - 1));
	// �ϳ��� ���ȣ���� �ϸ鼭 memo�� cost���� ���� �ּ� ����� ���Ѵ�.
	return memo[row][col];
}

int Min(int x, int y, int z) {
	if (x < y) {
		if (x < z) return x;
		else return z;
	}
	else {
		if (y < z) return y;
		else return z;
	}
}

void initialize(int min[MAX_ROW][MAX_COL]) {
	srand(time(NULL));
	for (int i = 0; i < MAX_ROW; i++)
		for (int j = 0; j < MAX_COL; j++) {
			memo[i][j] = -1;
			min[i][j] = rand() % (10 - 1 + 1) + 1;
		}
}

void print(int arr[MAX_ROW][MAX_COL]) {
	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_COL; j++)
			printf("%3d ", arr[i][j]);
		printf("\n");
	}
	printf("\n");
}