//#include <stdio.h>
//#include <time.h> // 병력들을 랜덤하게 정하기 위한 헤더파일
//#include <Windows.h> // 시간을 멈춰서 보기 편하게 하기 위한 헤더파일
//#define TIME 1000
//#define MAX_SOLDIER 30
//#define MIN_SOLDIER 10
//#define MAX_ROW 4
//#define MAX_COL 4
//
//typedef struct {
//	char* flag;
//	int soldier;
//} kingdom;
//
//typedef struct {
//	short int row;
//	short int col;
//	short int dir;
//} element;
//
//typedef struct {
//	short int vert;
//	short int horiz;
//} offsets;
//
//
///*		VARIABLES		*/	
//offsets move[8];
//kingdom myKingdom;
//element min;
//int mark[MAX_ROW][MAX_COL] = { 0, };
//
//
///*		FUNCTION		*/	
//void setSoldier(kingdom(*king)[MAX_COL]); // 맨 처음에 성의 병력을 랜덤하게 정해주는 함수
//void Trespass(kingdom(*king)[MAX_COL], short int row, short int col, int dir, int* cnt);
//void printArea(kingdom(*king)[MAX_COL]); // 현황을 출력해주는 함수
//void inputArea(int* r, int* c); // 만약 모든 성을 침략하지 않았을 때 침입할 행과 열을 입력받는 함수
//int isSafe(int row, int col); // 다음 행과 열이 안전한 지 확인하는 함수
//void initializeOFFSETS(); // 방향을 초기화하는 함수
//
//
//void main() {
//	int row, col, cnt = 0;
//	srand(time(NULL));
//	myKingdom.flag = "◆"; // 자신의 성의 깃발
//	myKingdom.soldier = rand() % ((MAX_SOLDIER - 10) - MIN_SOLDIER + 1) + MIN_SOLDIER;
//	kingdom Castle[MAX_ROW][MAX_COL];
//
//	initializeOFFSETS();
//	setSoldier(Castle);
//	printArea(Castle); 
//	Trespass(Castle, min.row, min.col, 0, &cnt);
//	if (cnt != MAX_ROW * MAX_COL) {
//		printf("You Only invalide %d castle ..\n\tTry again !\n", cnt);
//		inputArea(&row, &col);
//		Trespass(Castle, row, col, 0, &cnt);
//	}
//	else
//		printf("\tYour Win !!\n\n");
//	printArea(Castle);
//}
//
//void inputArea(int* r, int* c) {
//	printf("Choose area where you will invade : ");
//	scanf_s("%d %d", r, c);
//}
//
//int isSafe(int row, int col) { // 다음 행과 열이 안전하면 1을 반환하고 아닐 시 0을 반환한다.
//	if (row >= 0 && row < MAX_ROW && col >= 0 && col < MAX_COL)
//		return 1;
//	else return 0;
//}
//
//void Trespass(kingdom(*castle)[MAX_COL], short int row, short int col, int dir, int* cnt) {
//
//	int next_Row, next_Col;
//
//	if (*cnt == MAX_ROW * MAX_COL)
//		return;
//
//	// 침략해도 되는 상황이면 깃발을 자신의 것으로 바꾼 후 병력을 줄인다.
//	if ((*(castle + row) + col)->soldier < myKingdom.soldier && !mark[row][col]) {
//		mark[row][col] = 1;
//		(*(castle + row) + col)->flag = "◆"; 
//		(*(castle + row) + col)->soldier /= 4;
//		myKingdom.soldier += 2;
//		dir = 0;
//		*cnt += 1;
//		printArea(castle);
//		while (dir < 8) { // dir이 8이 되기전까지 반복하는 함수 
//			next_Row = row + move[dir].vert; 
//			next_Col = col + move[dir].horiz;
//
//			// next_Row, next_Col을 사용하여 침략해도 되는 영역인지 확인한 후 재귀호출한다.
//			if (isSafe(next_Row, next_Col) && !mark[next_Row][next_Col] && (*(castle + next_Row) + next_Col)->soldier < myKingdom.soldier) {
//				Trespass(castle, next_Row, next_Col, dir, cnt);
//			}
//			else dir++;
//		}
//	}
//}
//
//void setSoldier(kingdom(*castle)[MAX_COL]) { // 상대국의 병력을 무작위로 설정하는 함수
//	min.dir = MAX_SOLDIER;
//	srand(time(NULL));
//	for (int i = 0; i < MAX_ROW; i++) 
//		for (int j = 0; j < MAX_COL; j++) {
//			(*(castle + i) + j)->flag = "◇";
//			(*(castle + i) + j)->soldier = rand() % (MAX_SOLDIER - MIN_SOLDIER + 1) + MIN_SOLDIER;
//			if ((*(castle + i) + j)->soldier < min.dir) { // 최소 병력의 위치를 저장하는 작업
//				min.row = i;
//				min.col = j;
//				min.dir = (*(castle + i) + j)->soldier;
//			}
//		}
//}
//
//void printArea(kingdom(*castle)[MAX_COL]) { // 1초 기다렸다가 왕국의 상태를 표시해주는 함수이다.
//	Sleep(TIME);
//	printf("\tKingdom\n");
//	for (int i = 0; i < MAX_ROW; i++) {
//		for (int j = 0; j < MAX_COL; j++)
//			printf("%s %d  ", (*(castle + i) + j)->flag, (*(castle + i) + j)->soldier);
//		printf("\n\n");
//	}
//	printf("Your Kingdom's soldier : %s %d\n\n", myKingdom.flag, myKingdom.soldier);
//}
//
//void initializeOFFSETS() {
//	/*	N	*/
//	move[0].vert = -1;
//	move[0].horiz = 0;
//	/*	NE	*/
//	move[1].vert = -1;
//	move[1].horiz = 1;
//	/*	E	*/
//	move[2].vert = 0;
//	move[2].horiz = 1;
//	/*	SE	*/
//	move[3].vert = 1;
//	move[3].horiz = 1;
//	/*	S	*/
//	move[4].vert = 1;
//	move[4].horiz = 0;
//	/*	SW	*/
//	move[5].vert = 1;
//	move[5].horiz = -1;
//	/*	W	*/
//	move[6].vert = 0;
//	move[6].horiz = -1;
//	/*	NW	*/
//	move[7].vert = -1;
//	move[7].horiz = -1;
//}