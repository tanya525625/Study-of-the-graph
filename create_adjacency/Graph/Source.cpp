#include "Header.h"

int main()
{
	const int nodes_count = 51; // number of nodes
	const int edges_count = 335; // number of edges
	int** adj_matrix = new int*[nodes_count];
	for (int i = 0; i < nodes_count; i++)
		adj_matrix[i] = new int[nodes_count];

	adj_matrix = create_adjMatrix(nodes_count, edges_count);
	create_adjList(nodes_count, adj_matrix);

	system("pause");
	return 0;
}