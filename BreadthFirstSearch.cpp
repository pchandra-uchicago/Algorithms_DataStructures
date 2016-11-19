#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<list>
#include<algorithm>

using namespace std;

class Graph
{
	private:int V;
			list<int> *adj;
	public: Graph(int V);
			void addEdge(int v, int w);
			void breadthFirstSearch(int source);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
}

void Graph::breadthFirstSearch(int source)
{
	vector<bool> visited(V);
	visited.assign(V, false);
	queue<int> q;
	visited[source] = true;
	q.push(source);
	while (!q.empty())
	{
		source = q.front();
		cout << source << " ";
		q.pop();
		for (auto it = adj[source].begin(); it != adj[source].end(); it++)
		{
			if (!visited[*it])
			{
				visited[*it] = true;
				q.push(*it);
			}
		}
	}	
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
	cout << "Breadth First Traversal(starting from vertex 2) " <<" \n";
	g.breadthFirstSearch(2);
	_getch();
	return 0;
}