#include <stdio.h>
#include <stdlib.h>
#define V 5

int minKey(int key[], int mstSet[]);
void printMST(int parent[], int graph[V][V]);
void primMST(int graph[V][V]);

void main() {
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };
	primMST(graph);

}

int minKey(int key[], int mstSet[]) { // �迭���� �ּҺ���� ��� ��θ� ã�� ����
	int min = INT_MAX, min_index;
	for (int i = 0; i < V; i++)
		if (mstSet[i] == 0 && key[i] < min)
		{
			min = key[i];
			min_index = i;
		}
	return min_index;
}

void printMST(int parent[], int graph[V][V]) { 
	printf("Edge \t Weight\n");
	for (int i = 1; i < V; i++)
		printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V]) { // ���� �˰����� �̿��Ͽ� �ּ� ����� ã�´�.
	int parent[V]; // �ּ� ����� ����ִ� graph ������ �迭�� ���� ���
	int key[V];
	int mstSet[V];
	
	for (int i = 0; i < V; i++) { // key���� mstSet�� �ʱ�ȭ�Ѵ�.
		key[i] = INT_MAX;
		mstSet[i] = 0;
	}
	key[0] = 0;
	parent[0] = -1;

	for (int cnt = 0; cnt < V; cnt++) {
		int u = minKey(key, mstSet); // u : �ּ� ���� ����ִ� index�� �����Ѵ�
		mstSet[u] = 1;
		for (int v = 0; v < V; v++)
			// �������� ����Ǿ��ְ� �ּ� ��� ������ ã�� ������ �� �׷��� �������� �ּڰ��� ã�� ����
			if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) 
			{
				parent[v] = u;
				key[v] = graph[u][v];
			}
	}
	printMST(parent, graph);
}

