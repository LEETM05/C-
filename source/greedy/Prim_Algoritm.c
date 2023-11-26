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

int minKey(int key[], int mstSet[]) { // 배열에서 최소비용이 드는 경로를 찾는 과정
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

void primMST(int graph[V][V]) { // 프림 알고리즘을 이용하여 최소 비용을 찾는다.
	int parent[V]; // 최소 비용이 들어있는 graph 이차원 배열의 열을 담당
	int key[V];
	int mstSet[V];
	
	for (int i = 0; i < V; i++) { // key값과 mstSet을 초기화한다.
		key[i] = INT_MAX;
		mstSet[i] = 0;
	}
	key[0] = 0;
	parent[0] = -1;

	for (int cnt = 0; cnt < V; cnt++) {
		int u = minKey(key, mstSet); // u : 최소 값이 들어있는 index를 저장한다
		mstSet[u] = 1;
		for (int v = 0; v < V; v++)
			// 정점끼리 연결되어있고 최소 비용 간선을 찾지 못했을 때 그래프 열내에서 최솟값을 찾는 과정
			if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) 
			{
				parent[v] = u;
				key[v] = graph[u][v];
			}
	}
	printMST(parent, graph);
}

