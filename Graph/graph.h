#ifndef GRAPH_H
#define GRAPH_H

#include<list>

/*
template<typename V>
class Vertex {
    friend class Graph<typename Vertex, typename Edge>;
public:
    int seq_number;
	V *adj_list;
	int adj_numer;
	Vertex(V)
	{
		seq_number = 0;
	}
}

class Edge {
	friend class Graph<typename Vertex, typename Edge>;
public:
    V src;
    V dest;
	int weight;
	int seq_number;
	Edge(V s, V d, int w)
	{
		this.src = s; this.dest = d; this.weight = w;
	}
	V getSource()
	{
		return this.src;
	}
	V getDestination()
	{
		return this.dest;
	}
}
*/

template<typename T>
class Graph {
public:
	Graph(int, int)
    ~Graph()
	void insertVertex(int)
    void insertEdge(int, int)

	void breathFirstSearch(int, int);
	void depthFirstSearch(int, int);
private:
	void depthFirstSearchHelper(int, int);

	int v_n, e_n;
    int current_v_n, current_e_n;
	std::list<int> *adj_list;
	T **weight_list;
}

Graph:Graph(int vn, int en)
{
	this.v_n = vn;
    this.e_n = en;
    this.vertex_list = new std::list<V> [v_n];
    this.weight_list = new T [v_n];
	for(int i = 0; i < v_n; i++)
	{
		this.weight_list[i] = new T [v_n];
	}

	this.current_v_num = this.current_e_num = 0;
}

void Graph::insertVertex(Vertex v) 
{
    this.adj_list[current_v_num] = v;
	
	this.current_v_number++;
}
  
void Graph::insertEdge(int s, int d, T w)
{
	this.adj_list[current_v_num].push_back(d);
	this.weight_list[s][d] = w;

	this.current_e_number++;
}

void Graph::breathFirstSearch(int s, int d)
{
	std::list<int>::iterator it;
	std::list<int> adj_vertex;
	bool _visited[this.v_n];

	for (it=mylist[s].begin(); it!=mylist[s].end(); ++it)
	{
		adj_vertex.push_back(*it);
	}

	while(true)
	{
		int cur_v = adj_vertex.front();
		std::cout<<" "<<cur_v;
		if(cur_v == d) 
			break;

		adj_vertex.pop_front();
		_visited[cur_v] = true;

		for (it=mylist[cur_v].begin(); it!=mylist[cur_v].end(); ++it)
		{
			if(!_visited[*it])
			{
				adj_vertex.push_back(*it);
				_visited[*it] = true;
			}
		}
	}

	std::cout<<std::endl;
}

void Graph<T>::depthFirstSearch(int s, int d)
{
	std::list<int>::iterator it;
	std::list<int> adj_vertex;
	bool _visited[this.v_n];

	for (it=mylist[s].begin(); it!=mylist[s].end(); ++it)
	{
		if(*it == d) break;
		this.depthFirstSearchHelper(*it, d);
	}
}

void Graph<T>::depthFirstSearchHelper(int s, int d, int *_visited)
{
	for (it=mylist[s].begin(); it!=mylist[s].end(); ++it)
	{
		if(*it == d) return;
		if(!_visited[*it])
			this.depthFirstSearch(*it, d);
	}
}
