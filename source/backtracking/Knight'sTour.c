///*		program : Find path	*/
///*		name : Tae Min		*/
///*		Date : 2023-07-14	*/
//
//
//#include <stdio.h>
//#define N 8 // ü������ ����
//
//int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 }; // ����Ʈ�� x�� �̵�����
//int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 }; // ����Ʈ�� y�� �̵�����
// 
//
//int KnightsTour(int x, int y, int cnt, int(*ptr)[N]);
//int Safe(int x, int y, int(*ptr)[N]);
//void find_path();
//void printKnightsWay(int(*ptr)[N]);
//
//void main() {
//	find_path();
//}
//
//void find_path() {
//	int Chess[N][N];
//	for (int i = 0; i < N; i++) // ����Ʈ�� �ٴ� ����� ��� -1�� �ʱ�ȭ�Ѵ�.
//		for (int j = 0; j < N; j++)
//			Chess[i][j] = -1;
//	Chess[0][0] = 0; // ������ �ʱ�ȭ
//	if (KnightsTour(0, 0, 1, Chess) == 0) {
//		printf("There is no way !\n");
//	}
//	else {
//		printKnightsWay(Chess);
//	}
//}
//
//int KnightsTour(int x, int y, int cnt, int(*ptr)[N]) {
//	int next_x, next_y;
//	if (cnt == N * N)
//		return 1; // Ž�� ����
//
//	for (int i = 0; i < 8; i++) {
//
//		next_x = x + xMove[i];
//		next_y = y + yMove[i];
//
//		if (Safe(next_x, next_y, ptr)) {
//			*(*(ptr + next_x) + next_y) = cnt; // ü���ǿ� ����Ʈ�� �̵����� ����
//			if (KnightsTour(next_x, next_y, cnt + 1, ptr) == 1) // ���ȣ��
//				return 1;
//			else 
//				*(*(ptr + next_x) + next_y) = -1; // ���ٰ� �ٽ� �þƿ��� -1�� �ʱ�ȭ
//		}
//	}
//	return 0;
//}
//
//int Safe(int x, int y, int(*ptr)[N]) { // ������ ��ǥ�� ����Ʈ�� �� �� �ִ� ������ Ȯ��
//	if (x >= 0 && x < N && y >= 0 && y < N && *(*(ptr + x) + y) == -1)
//		return 1;
//	else return 0;
//}
//
//void printKnightsWay(int(*ptr)[N]) { // Chess�ǿ��� ����Ʈ�� ������ ���� ����Ѵ�.
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++)
//			printf("%2d ", *(*(ptr + i) + j));
//		printf("\n");
//	}
//}
//
