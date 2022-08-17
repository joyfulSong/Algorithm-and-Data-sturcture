#include <iostream>
using namespace std;

#define MAX_VERTICES 256    // 최대 정점 개수

class AdjMatrixGraph
{
private:
	int size;                       // 정점의 개수
	char vertices[MAX_VERTICES];        // 정점의 이름
	int adj_matrix[MAX_VERTICES][MAX_VERTICES];    // 인접 행렬

public:
	AdjMatrixGraph()
	{
		reset();
	}
	~AdjMatrixGraph() {}

	char getVertex(int i)
	{
		return vertices[i];
	}
	int getEdge(int i, int j)
	{
		return adj_matrix[i][j];
	}
	void setEdge(int i, int j, int val)
	{
		adj_matrix[i][j] = val;
	}

	// 그래프 초기화
	void reset()
	{
		for (int i = 0; i < MAX_VERTICES; i++)
		{
			for (int j = 0; j < MAX_VERTICES; j++)
			{
				setEdge(i, j, 0);
			}
		}
		size = 0;
	}

	// 정점 삽입
	void insertVertex(char name)
	{
		if (isFull())
		{
			cout << "Graph vertex full error" << endl;
			return;
		}

		vertices[size] = name;
		++size;
	}

	// 간선 삽입 (무방향 그래프)
	void insertEdge(int u, int v)
	{
		setEdge(u, v, 1);       // 가중치 그래프에서는 1이 아닌 가중치 삽입
		setEdge(v, u, 1);       // 방향 그래프에서는 삭제 (<u,v>만 존재)
	}

	// 그래프 정보 출력
	void display()
	{
		cout << "vertex size : " << size << endl;
		cout << "    ";
		for (int i = 0; i < size; i++)
		{
			cout << getVertex(i) << " ";
		}
		cout << endl;

		for (int i = 0; i < size; i++)
		{
			cout << getVertex(i) << " : ";
			for (int j = 0; j < size; j++)
			{
				cout << getEdge(i, j) << " ";
			}
			cout << endl;
		}
	}

	bool isEmpty() {
		return size == 0;
	}
	bool isFull() {
		return size >= MAX_VERTICES;
	}
};

int main() {
	AdjMatrixGraph graph;

	// 정점 삽입 (A, B, C, D)
	graph.insertVertex('A');    // 0
	graph.insertVertex('B');    // 1
	graph.insertVertex('C');    // 2
	graph.insertVertex('D');    // 3

	// 간선 삽입
	graph.insertEdge(0, 1);     // A->B
	graph.insertEdge(0, 2);     // A->C
	graph.insertEdge(0, 3);     // A->D
	graph.insertEdge(2, 3);     // C->D

	graph.display();

	return 0;
}

// https://suyeon96.tistory.com/32
// 위 링크에 6가지 경우 다 있음
// 인접 행렬, 인접 리스트 구현
// 각각에 대해 DFS, BFS 있음

// vertex size : 4
//     A B C D
// A : 0 1 1 1
// B : 1 0 0 0
// C : 1 0 0 1
// D : 1 0 1 0
