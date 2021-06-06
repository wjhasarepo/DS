#include<list>
#include<iostream>
#include<graph.h>

int main(int argc, char **argv)
{
	Edge e01(0, 1, -1);
	Edge e05(0, 5, 2);
	Edge e12(1, 2, 2);
	Edge e15(1, 5, -2);
	Edge e23(2, 3, 5);
	Edge e24(2, 4, 1);
	Edge e43(4, 3, -4);
	Edge e45(4, 5, 3);
	Edge e51(5, 1, 2);
	Edge e52(5, 2, 3);
	
	int node_count = 6;
	int source_node = 0;

	list<Edge> edge_list = { e01, e05, e12, e15, e23, e24, e43, e45, e51, e52 };
	Graph g(node_count, edge_list);
	
	return 0;
}
