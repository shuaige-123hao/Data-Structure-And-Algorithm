#include <iostream>
using namespace std;
class Graph {
private:
	struct edgenode {
		int end;
		int weight;
		edgenode* next;
	};
	int vertices;
	struct vernodes {
		int vertex;
		edgenode* head;
	};
	vernodes* nodes;
public:Graph(int vertices);
	  ~Graph();
	  void addedge(int begin, int end, int distances);
	  void pr();
};
Graph::Graph(int vertices) {
	this->vertices = vertices;
	this->nodes = new vernodes[vertices];
	for (int i = 0; i < vertices; i++) {
		nodes[i].vertex = i;
		this->nodes[i].head = NULL;
	}
}
Graph::~Graph() {
	for (int i = 0; i < vertices; i++) {
		if (nodes[i].head == NULL) {
			continue;
		}
		edgenode* curr = nodes[i].head;
		while (curr) {
			edgenode* temp = curr;
			curr = curr->next;
			delete[]temp;
		}
	}
}
void Graph::addedge(int begin, int end, int distances) {
	edgenode* temp = new edgenode;
	temp->weight = distances;
	temp->end = end;
	temp->next = nodes[begin].head;
	nodes[begin].head = temp;
}
void Graph::pr() {
	for (int i = 0; i < vertices; i++) {
		if (nodes[i].head == NULL) {
			continue;
		}
		cout << nodes[i].vertex << ":";
		edgenode* curr = nodes[i].head;
		while (curr) {
			cout << curr->end << ' ' << curr->weight;
			curr = curr->next;
		
		}
		cout << endl;
	}
}
int main() {
	Graph g(5);
	g.addedge(0,1 , 4);
	g.addedge(0,2 ,2 );
	g.addedge(1, 2, 3);
	g.addedge(2, 3,4 );
	g.addedge(3,4 ,2 );
	g.pr();
	return 0;
}