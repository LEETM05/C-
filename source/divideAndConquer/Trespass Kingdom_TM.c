//#include <stdio.h>
//#include <time.h> // ���µ��� �����ϰ� ���ϱ� ���� �������
//#include <Windows.h> // �ð��� ���缭 ���� ���ϰ� �ϱ� ���� �������
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
//void setSoldier(kingdom(*king)[MAX_COL]); // �� ó���� ���� ������ �����ϰ� �����ִ� �Լ�
//void Trespass(kingdom(*king)[MAX_COL], short int row, short int col, int dir, int* cnt);
//void printArea(kingdom(*king)[MAX_COL]); // ��Ȳ�� ������ִ� �Լ�
//void inputArea(int* r, int* c); // ���� ��� ���� ħ������ �ʾ��� �� ħ���� ��� ���� �Է¹޴� �Լ�
//int isSafe(int row, int col); // ���� ��� ���� ������ �� Ȯ���ϴ� �Լ�
//void initializeOFFSETS(); // ������ �ʱ�ȭ�ϴ� �Լ�
//
//
//void main() {
//	int row, col, cnt = 0;
//	srand(time(NULL));
//	myKingdom.flag = "��"; // �ڽ��� ���� ���
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
//int isSafe(int row, int col) { // ���� ��� ���� �����ϸ� 1�� ��ȯ�ϰ� �ƴ� �� 0�� ��ȯ�Ѵ�.
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
//	// ħ���ص� �Ǵ� ��Ȳ�̸� ����� �ڽ��� ������ �ٲ� �� ������ ���δ�.
//	if ((*(castle + row) + col)->soldier < myKingdom.soldier && !mark[row][col]) {
//		mark[row][col] = 1;
//		(*(castle + row) + col)->flag = "��"; 
//		(*(castle + row) + col)->soldier /= 4;
//		myKingdom.soldier += 2;
//		dir = 0;
//		*cnt += 1;
//		printArea(castle);
//		while (dir < 8) { // dir�� 8�� �Ǳ������� �ݺ��ϴ� �Լ� 
//			next_Row = row + move[dir].vert; 
//			next_Col = col + move[dir].horiz;
//
//			// next_Row, next_Col�� ����Ͽ� ħ���ص� �Ǵ� �������� Ȯ���� �� ���ȣ���Ѵ�.
//			if (isSafe(next_Row, next_Col) && !mark[next_Row][next_Col] && (*(castle + next_Row) + next_Col)->soldier < myKingdom.soldier) {
//				Trespass(castle, next_Row, next_Col, dir, cnt);
//			}
//			else dir++;
//		}
//	}
//}
//
//void setSoldier(kingdom(*castle)[MAX_COL]) { // ��뱹�� ������ �������� �����ϴ� �Լ�
//	min.dir = MAX_SOLDIER;
//	srand(time(NULL));
//	for (int i = 0; i < MAX_ROW; i++) 
//		for (int j = 0; j < MAX_COL; j++) {
//			(*(castle + i) + j)->flag = "��";
//			(*(castle + i) + j)->soldier = rand() % (MAX_SOLDIER - MIN_SOLDIER + 1) + MIN_SOLDIER;
//			if ((*(castle + i) + j)->soldier < min.dir) { // �ּ� ������ ��ġ�� �����ϴ� �۾�
//				min.row = i;
//				min.col = j;
//				min.dir = (*(castle + i) + j)->soldier;
//			}
//		}
//}
//
//void printArea(kingdom(*castle)[MAX_COL]) { // 1�� ��ٷȴٰ� �ձ��� ���¸� ǥ�����ִ� �Լ��̴�.
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