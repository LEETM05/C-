///*		program : Find path	*/
///*		name : Tae Min		*/
///*		Date : 2023-07-14	*/
//
//
//#include <stdio.h>
//#include <stdlib.h>
//#define EXIT_ROW 10
//#define EXIT_COL 10
//#define MAX_STACK 144
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
///*		FUNCTION		*/	
//void path();
//void push(element pos);
//element pop(int* tp);
//void initializeOFFSETS();
//
///*		VARIABLES		*/	
//offsets move[8];
//element stack[MAX_STACK];
//int mark[EXIT_ROW + 2][EXIT_COL + 2];
//int maze[EXIT_ROW + 2][EXIT_COL + 2] = {
//	{1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,0,1,1,1,1,1,1,1,0,1,1},
//	{1,0,1,0,1,0,0,0,0,1,0,1},
//	{1,1,0,1,0,1,1,1,0,1,1,1},
//	{1,1,0,1,1,0,1,1,1,1,1,1},
//	{1,1,0,1,1,0,0,0,1,1,1,1},
//	{1,1,0,1,1,0,1,1,1,0,1,1},
//	{1,0,1,1,0,1,0,1,0,1,0,1},
//	{1,0,1,0,1,1,0,1,0,1,0,1},
//	{1,1,1,0,1,1,0,1,0,1,0,1},
//	{1,1,1,0,1,1,1,0,1,1,0,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1}
//};
//int top;
//
//void main() {
//	initializeOFFSETS();
//	path();
//}
//
//
///*		PATH FUCNTION	*/
//void path() {
//	int i, row, col, nextRow, nextCol, dir, found = 0;
//	element position;
//	mark[1][1] = 1;
//	top = 1;
//	stack[0].row = 1;
//	stack[0].col = 1;
//	stack[0].dir = 1;
//	while (top > -1 && !found) { // stack 이 비지 않고 출구를 찾기 전까지 반복
//		position = pop(&top); // stack의 top에 위치에 있는 element를 리턴한다.
//		row = position.row; 
//		col = position.col;	
//		dir = position.dir;	
//		while (dir < 8 && !found) { // dir 이 8이 되기 전이면서 출구를 찾기 전까지 반복
//			nextRow = row + move[dir].vert; // 
//			nextCol = col + move[dir].horiz; // 
//			if (nextRow == EXIT_ROW && nextCol == EXIT_COL) // 출구를 찾았을 때 found = 1
//				found = 1;
//			else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol]) { // 방문하지 않았고 미로가 1이 아닐때 ( 길이 있을 때 )
//				mark[nextRow][nextCol] = 1;
//				position.row = row;
//				position.col = col;
//				position.dir = ++dir;
//				push(position);
//				row = nextRow;
//				col = nextCol;
//				dir = 0;
//			}
//			else
//				dir++;
//		}
//	}
//	if (found) {
//		printf("the path is : \n");
//		printf("row\tcol\n");
//		for (i = 0; i < top; i++)
//			printf("%2d%5d\n", stack[i].row, stack[i].col);
//		printf("%2d%5d\n", row, col);
//		printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
//	}
//	else
//		printf("The maze dose not have a path\n");
//}
//
//element pop(int* tp) {
//	if (top < -1) {
//		fprintf(stderr, "stack is empty\n");
//		exit(1);
//	}
//	return stack[--top];
//}
//
//void push(element pos) {
//	if (top > MAX_STACK) {
//		fprintf(stderr, "stack is full\n");
//		exit(1);
//	}
//	stack[top].row = pos.row;
//	stack[top].col = pos.col;
//	stack[top++].dir = pos.dir;
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