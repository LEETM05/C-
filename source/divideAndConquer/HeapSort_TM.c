#include <stdio.h>
#include <Windows.h> // Sleep 함수를 사용하기 위한 헤더파일
#define SWAP(x,y,t) {(t) = (x); (x) = (y); (y) = (t);}
#define MAX_SIZE 11
#define TIME 1000

typedef struct {
	int key;
} element;

void adjust(element a[], int root, int n); // 최대 힙을 구하는 함수
void heapSort(element a[], int n); // 힙정렬하는 함수
void input(element a[]); // 입력받는 함수
void printHeapSort(element a[]); // 1초 간격을 두고 최대힙을 구하는 과정과 정렬하는 과정을 보여주는 함수

int main() {
	element heap[MAX_SIZE] = { 0, };
	input(heap);
	heapSort(heap, 10);
	printf("\tsorted array\n");
	printHeapSort(heap);
	return 0;
}

void adjust(element a[], int root, int n) { // 최대 힙을 구하는 함수
	int child, rootkey;
	element temp;
	temp = a[root];
	rootkey = a[root].key;
	child = 2 * root;
	while (child <= n) {
		if ((child < n) && (a[child].key < a[child + 1].key)) // 두 개의 index가 정렬되어있다고 판단될 때 다음 인덱스로 간다.
			child++;
		if (rootkey > a[child].key) // 만약 root의 key값이 child의 key값보다 크면 종료
			break;
		else { // 그 외에는 child / 2에 child를 넣어주고 child를 2배로 만든다.
			a[child / 2] = a[child];
			child *= 2;
		}
	}
	a[child / 2] = temp; // 마지막에는 temp에 있던 root의 키 값을 최대힙 과정으로 바뀐 child/2에 삽입
}

void heapSort(element a[], int n) { // 힙정렬 함수
	int i;
	element temp;
	printf("\tFind MAX heap\n");
	for (i = n / 2; i > 0; i--) { // 최대힙을 구한다.
		adjust(a, i, n);
		printHeapSort(a);
	}
	printf("\tProcedure of Sortion\n");
	for (i = n - 1; i > 0; i--) { // 최대힙에서 root의 값을 맨 뒤로 보낸 후 범위를 줄여 다시 최대힙을 구한다.
		SWAP(a[1], a[i + 1], temp);
		adjust(a, 1, i);
		printHeapSort(a);
	}
}

void input(element a[]) { // 배열을 입력받는 함수
	printf("input data : ");
	for (int i = 1; i < MAX_SIZE; i++) // 1부터 정렬하기 때문에 1부터 받는다.
		scanf_s("%d", &a[i].key);
}

void printHeapSort(element a[]) {
	Sleep(TIME); // 1초 기다렸다가 출력한다.
	for (int i = 1; i < MAX_SIZE; i++)
		printf("%4d", a[i]);
	printf("\n\n");
}

