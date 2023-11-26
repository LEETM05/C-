#include <stdio.h>
#include <Windows.h> // Sleep �Լ��� ����ϱ� ���� �������
#define SWAP(x,y,t) {(t) = (x); (x) = (y); (y) = (t);}
#define MAX_SIZE 11
#define TIME 1000

typedef struct {
	int key;
} element;

void adjust(element a[], int root, int n); // �ִ� ���� ���ϴ� �Լ�
void heapSort(element a[], int n); // �������ϴ� �Լ�
void input(element a[]); // �Է¹޴� �Լ�
void printHeapSort(element a[]); // 1�� ������ �ΰ� �ִ����� ���ϴ� ������ �����ϴ� ������ �����ִ� �Լ�

int main() {
	element heap[MAX_SIZE] = { 0, };
	input(heap);
	heapSort(heap, 10);
	printf("\tsorted array\n");
	printHeapSort(heap);
	return 0;
}

void adjust(element a[], int root, int n) { // �ִ� ���� ���ϴ� �Լ�
	int child, rootkey;
	element temp;
	temp = a[root];
	rootkey = a[root].key;
	child = 2 * root;
	while (child <= n) {
		if ((child < n) && (a[child].key < a[child + 1].key)) // �� ���� index�� ���ĵǾ��ִٰ� �Ǵܵ� �� ���� �ε����� ����.
			child++;
		if (rootkey > a[child].key) // ���� root�� key���� child�� key������ ũ�� ����
			break;
		else { // �� �ܿ��� child / 2�� child�� �־��ְ� child�� 2��� �����.
			a[child / 2] = a[child];
			child *= 2;
		}
	}
	a[child / 2] = temp; // ���������� temp�� �ִ� root�� Ű ���� �ִ��� �������� �ٲ� child/2�� ����
}

void heapSort(element a[], int n) { // ������ �Լ�
	int i;
	element temp;
	printf("\tFind MAX heap\n");
	for (i = n / 2; i > 0; i--) { // �ִ����� ���Ѵ�.
		adjust(a, i, n);
		printHeapSort(a);
	}
	printf("\tProcedure of Sortion\n");
	for (i = n - 1; i > 0; i--) { // �ִ������� root�� ���� �� �ڷ� ���� �� ������ �ٿ� �ٽ� �ִ����� ���Ѵ�.
		SWAP(a[1], a[i + 1], temp);
		adjust(a, 1, i);
		printHeapSort(a);
	}
}

void input(element a[]) { // �迭�� �Է¹޴� �Լ�
	printf("input data : ");
	for (int i = 1; i < MAX_SIZE; i++) // 1���� �����ϱ� ������ 1���� �޴´�.
		scanf_s("%d", &a[i].key);
}

void printHeapSort(element a[]) {
	Sleep(TIME); // 1�� ��ٷȴٰ� ����Ѵ�.
	for (int i = 1; i < MAX_SIZE; i++)
		printf("%4d", a[i]);
	printf("\n\n");
}

