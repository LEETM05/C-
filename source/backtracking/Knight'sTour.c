///*		program : Find path	*/
///*		name : Tae Min		*/
///*		Date : 2023-07-14	*/
//
//
//#include <stdio.h>
//#define N 8 // 체스판의 길이
//
//int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 }; // 나이트의 x축 이동방향
//int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 }; // 나이트의 y출 이동방향
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
//	for (int i = 0; i < N; i++) // 나이트가 다닐 길들을 모두 -1로 초기화한다.
//		for (int j = 0; j < N; j++)
//			Chess[i][j] = -1;
//	Chess[0][0] = 0; // 시작점 초기화
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
//		return 1; // 탐색 종료
//
//	for (int i = 0; i < 8; i++) {
//
//		next_x = x + xMove[i];
//		next_y = y + yMove[i];
//
//		if (Safe(next_x, next_y, ptr)) {
//			*(*(ptr + next_x) + next_y) = cnt; // 체스판에 나이트의 이동순서 대입
//			if (KnightsTour(next_x, next_y, cnt + 1, ptr) == 1) // 재귀호출
//				return 1;
//			else 
//				*(*(ptr + next_x) + next_y) = -1; // 갔다가 다시 올아오면 -1로 초기화
//		}
//	}
//	return 0;
//}
//
//int Safe(int x, int y, int(*ptr)[N]) { // 조사할 좌표가 나이트가 갈 수 있는 길인지 확인
//	if (x >= 0 && x < N && y >= 0 && y < N && *(*(ptr + x) + y) == -1)
//		return 1;
//	else return 0;
//}
//
//void printKnightsWay(int(*ptr)[N]) { // Chess판에서 나이트가 지나간 길을 출력한다.
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++)
//			printf("%2d ", *(*(ptr + i) + j));
//		printf("\n");
//	}
//}
//
