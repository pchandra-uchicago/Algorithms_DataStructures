#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

class Graph {
	private:int V;
		list<int> *adj;
		void dfsUtility(int v, bool visited[]);
	public: Graph(int V);
		void addEdge(int v, int w);
		void depthFirstSearch(int v);		
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::dfsUtility(int v, bool visited[]) {
	// Mark the current node as visited and print it
	visited[v] = true;
	cout << v << " ";
	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			dfsUtility(*i, visited);
}

void Graph::depthFirstSearch(int v) {
	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	// Call the recursive helper function to print DFS traversal
	dfsUtility(v, visited);
}

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	cout << "Following is Depth First Traversal (starting from vertex 2) \n";
	g.depthFirstSearch(2);
	_getch();
	return 0;
}
