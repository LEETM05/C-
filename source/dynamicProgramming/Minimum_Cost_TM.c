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

int FindMinCost(int cost[MAX_ROW][MAX_COL], int row, int col) { // 최소 비용을 찾는 

	if (row < 0 || col < 0)
		return INT_MAX;
	// 만약 index 범위 외에는 최대 int 값을 반환해서 해당 index가 최소값이 되도록 한다.
	else if (row == 0 && col == 0) {
		memo[0][0] = cost[0][0];
		return cost[0][0];
	}
	// memo에 이미 값이 들어있다면 그 값을 반환한다.
	if (memo[row][col] != -1)
		return memo[row][col];
	
	memo[row][col] = cost[row][col] + Min(FindMinCost(cost, row - 1, col - 1), FindMinCost(cost, row - 1, col), FindMinCost(cost, row, col - 1));
	// 하나씩 재귀호출을 하면서 memo에 cost값과 다음 최소 비용을 더한다.
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