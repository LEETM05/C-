//#include <stdio.h>
//#include <Windows.h>
//#define TIME 1000
//#define SWAP(x,y,t) {(t) = (x); (x) = (y); (y) = (t);}
//#define MAX_SIZE 11
//
//typedef struct {
//	int key;
//} element;
//
//void merge(element iniList[], element mergedList[], int i, int m, int n);
//void mergePass(element initList[], element mergedList[], int n, int s);
//void mergeSort(element a[], int n);
//void input(element a[]);
//void printMergedList(element a[]);
//
//void main() {
//	element mergelist[MAX_SIZE];
//	input(mergelist);
//	mergeSort(mergelist, MAX_SIZE - 1);
//	printMergedList(mergelist);
//}
//
//void merge(element initList[], element mergedList[], int i, int m, int n) {
//	int j, k, t;
//	j = m + 1;
//	k = i;
//	while (i <= m && j <= n) {
//		if (initList[i].key <= initList[j].key)
//			mergedList[k++] = initList[i++];
//		else mergedList[k++] = initList[j++];
//	}
//	if (i > m)
//		for (t = j; t <= n; t++)
//			mergedList[t] = initList[t];
//	else
//		for (t = i; t <= m; t++)
//			mergedList[k + t - i] = initList[t];
//}
//
//void mergePass(element initList[], element mergedList[], int n, int s) {
//	int i, j;
//	for (i = 1; i <= n - 2 * s + 1; i += 2 * s)
//		merge(initList, mergedList, i, i + s - 1, i + 2 * s - 1);
//	if (i + s - 1 < n)
//		merge(initList, mergedList, i, i + s - 1, n);
//	else
//		for (j = i; j <= n; j++)
//			mergedList[j] = initList[j];
//}
//
//void mergeSort(element a[], int n) {
//	int s = 1;
//	element extra[MAX_SIZE];
//	while (s < n) {
//		mergePass(a, extra, n, s);
//		s *= 2;
//		mergePass(extra, a, n, s);
//		s *= 2;
//	}
//}
//
//void input(element a[]) {
//	printf("input random data : ");
//	for (int i = 1; i < MAX_SIZE; i++) {
//		scanf_s("%d", &a[i].key);
//	}
//}
//
//void printMergedList(element a[]) {
//	for (int i = 1; i < MAX_SIZE; i++)
//		printf("%d ", a[i].key);
//	printf("\n");
//}