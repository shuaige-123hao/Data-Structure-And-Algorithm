#include <iostream>
using namespace std;
#define inf -1
class Graph {
private:int vertices;
	int** edges;
public:
	Graph(int vertices);
	~Graph();
	void addedge(int begin, int end, int distance);
	void prt();
};
Graph::Graph(int vertices) {
	this->vertices = vertices;
	edges = new int* [vertices];
	for (int i = 0; i < vertices; i++) {
		edges[i] = new int[vertices];
		for (int j = 0; j < vertices; j++) {
			edges[i][j] = inf;
		}
	}
}
Graph::~Graph() {
	for (int i = 0; i < vertices; i++) {
		delete [] edges[i];
	}
	delete[]edges;
	vertices = 0;
}
void Graph::addedge(int begin, int end, int distance) {
	edges[begin][end] = distance;
}
void Graph::prt() {
	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < vertices; j++) {
			cout << edges[i][j] << ' ';
		}
		cout << endl;
	}
	
}
int main() {
	Graph g(5);
	g.addedge(0,1,1);
	g.addedge(0,2 ,3 );
	g.addedge(1, 2,2 );
	g.addedge(2,3 ,7 );
	g.addedge(3, 4, 9);
	g.addedge(4, 0, 4);
	g.addedge(4, 2, 5);
	g.prt();



	return 0;
}