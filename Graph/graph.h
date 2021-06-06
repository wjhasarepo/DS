#ifndef GRAPH_H
#define GRAPH_H

#include<list>
class Edge {
	public :
		
		Edge(int arg_src, int arg_dst, int arg_weight) : src(arg_src), dst(arg_dst), weight(arg_weight)
	
	{}
		int src;
		int dst;			
    		int weight;
};

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
	Graph() {};
	Graph (int arg_node_count, list<Edge> arg_edge_list) : node_count(arg_node_count), edge_list(arg_edge_list);					           {}
    	~Graph();
	//void insertVertex(int);
    	//void insertEdge(int, int);

	void breathFirstSearch(int, int);
	void depthFirstSearch(int, int);
	void singlePairShortestPath(int, int);
	void allPairShortestPath();
	void fordFulkerson(int, int);
private:
	void depthFirstSearchHelper(int, int);
	int min (int x, int y) { return x<y ? x : y; }

private:
	int current_v_n, current_e_n;
	std::list<int> *adj_list;
	T **weight_list;
	
	int node_count;
	list<Edge> edge_list;
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

void Graph<T>::singlePairShortestPath(int s) // Dijkstra Algorithm
{
	int *dist[this.v_n] = new int[v_n];

	for (int i = 0; i < v_n ; i++)
	{
		i == s? dist[i] = 0 : dist[i] = 65535;
	}

	std::list<int> vertexSet;

	for (int i = 0; i < v_n ; i++)
	{
		vertexSet.push_back(dist[i]);
	}

	while(!vertexSet.empty)
	{
		int cur_min = 65535;
		for (std::list<int>::iterator it=vertexSet.begin(); it!=vertexSet.end(); ++it)
		{
			if (*it < min) cur_min = *it;
		}
		vertexSet.remove(*it);
			
		for (it=mylist[cur_min].begin(); it!=mylist[cur_min].end(); ++it)
		{
			if (dist[cur_min] + weight_list[cur_min][*it] < dist[*it])
			{
				dist[*it] = dist[cur_min] + weight_list[cur_min][*it]
			}
		}
	}

	return dist[d];
}

void Graph<T>::singlePairShortestPathWithNegativeWeight(int s) 
{
	// Initialize the distance / cost from the source node to all other nodes to some max value.
	vector<int> distance(node_count, 999999999);
	
	// Distance/cost from the source node to itself is 0.
	distance[src] = 0;

	for (int i=0; i<node_count; i++) 
	{
		for (auto& it : edge_list) 
		{
			if (distance[it.dst] > distance[it.src] + it.weight) 
			{
				distance[it.dst] = distance[it.src] + it.weight;
			}
		}
	}		
	
	for (auto& it : edge_list) 
	{
		if (distance[it.dst] > distance[it.src] + it.weight) 
		{
			cout << "Negative weight cycle exist in the graph !!!" << endl;
		}
	}

	for (int i=0; i<node_count; i++)
		cout << "Source Node(" << src << ") -> Destination Node(" << i << ") : Length => " << distance[i] << endl;
		
}

void Graph<T>::allPairShortestPath() // Floyd-Warshall Algorithm
{
	int dist[v_n][v_n];
	
	for (int i = 0; i < v_n ; i++)
	{
		for (int j = 0; j < v_n ; j++)
		{
			dist[i][j] = 65536;
		}
	}

	for (int i = 0; i < n_v; i++)
	{
		for(int j = 0; j < n_v; j++)
		{
			for(int k = 0; k < n_v; k++)
			{
				if(weight_list[i][k] != 0 && weight_list[k][j] != 0 && dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	return dist;
}

void Graph<T>::fordFulkerson(int source, int sink)
{
	int i,j,u;

    int max_flow = 0;

	int flow[this.n_v][this.n_v];
	int pred[this.n_v];  // array to store augmenting path

	for (i = 0; i < n_v; i++)
        for (j = 0; j < n_v; j++)
             flow[u][v] = 0;

	while(this.breathFirstSearch(source, sink)) 
	{
		int increment = INF;
		for (u=n-1; pred[u]>=0; u=pred[u]) {
			increment = min(increment, this.weight_list[pred[u]][u]-flow[pred[u]][u]);
		}

		for (u=n-1; pred[u]>=0; u=pred[u]) {
			flow[pred[u]][u] += increment;
			flow[u][pred[u]] -= increment;
		}

		max_flow += increment;
	}
    // No augmenting path anymore. We are done.
    return max_flow;
}
