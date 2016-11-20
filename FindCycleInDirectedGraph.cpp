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
		bool isCyclicUtility(int v, vector<bool> visited, vector<bool> recursionStack);
	public: Graph(int V);
		void addEdge(int v, int w);
		bool isCyclic();
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);	
}

bool Graph::isCyclicUtility(int v, vector<bool> visited, vector<bool> recursionStack) {
	if (visited[v] == false) {
		/*mark the current node as visited and add it to recursion stack*/
		visited[v] = true;
		recursionStack[v] = true;
		for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
			if (!visited[*it] && isCyclicUtility(*it, visited, recursionStack))	return true;
			else if (recursionStack[*it]) return true;
		}
	}
	recursionStack[v] = false;
	return false;
}

bool Graph::isCyclic() {
	vector<bool> visited(V); vector<bool> recursionStack(V);
	visited.assign(V, false); recursionStack.assign(V,false);
	for (int i = 0; i < V; i++)
		if (isCyclicUtility(1, visited, recursionStack)) return true;
	return false;
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
	if (g.isCyclic())
		cout << "Graph contains cycle";
	else
		cout << "Graph doesn't contain cycle";
	_getch();
	return 0;
}
