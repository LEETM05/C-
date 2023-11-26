//#include <stdio.h>
//#include <windows.h>
//#define TIME 1000
//#define MAX_INDEX 10
//#define SWAP(x,y,t)  {(t) = (x); (x) = (y); (y) = (t);}
//
//typedef struct {
//	int key;
//} element;
//
//void quickSort(element a[], int left, int right); // �� ���� �Լ�
//void printSort(element a[], int left, int right); // ������ �迭���� ����ϴ� �Լ�
//void input(element a[]); // ������ key���� �Է¹��� �Լ�
//
//void main() {
//	element list[MAX_INDEX];
//	input(list);
//	printf("\nSorted data\t\t\tleft\tright\n");
//	quickSort(list, 0, 9);
//}
//
//void quickSort(element a[], int left, int right) {
//	int pivot, i, j;
//	element temp;
//	if (left < right) {
//		i = left;
//		j = right + 1;
//		pivot = a[left].key;
//		do {
//			do i++; while (a[i].key < pivot);
//			do j--; while (a[j].key > pivot);
//			if (i < j) SWAP(a[i], a[j], temp);
//		} while (i < j);
//		SWAP(a[left], a[j], temp);
//		printSort(a, left + 1, right + 1);
//		quickSort(a, left, j - 1);
//		quickSort(a, j + 1, right);
//	}
//}
//
//void input(element a[]) { // ������ key������ �Է¹��� �Լ�
//	printf("input random data : ");
//	for (int i = 0; i < MAX_INDEX; i++)
//		scanf_s("%d", &a[i].key);
//}
//
//void printSort(element a[], int left, int right) { // ���ĵ� �迭���� ����ϴ� �Լ�
//	Sleep(TIME);
//	for (int i = 0; i < MAX_INDEX; i++)
//		printf("%d ", a[i]);
//	printf("\t%d\t%d\n", left, right);
//	printf("\n");
//}