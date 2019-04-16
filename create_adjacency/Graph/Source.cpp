#include "Header.h"

int main()
{
	const int nodes_count = 51; // number of nodes
	const int edges_count = 338; // number of edges
	const int max_component_nodes_count = 25;
	string nodes_file_name = "nodes.csv";
	string edges_file_name = "undGraphEdges.csv";
	string output_adj_matrix_file_name = "adjacency_matrix_of_undGraph.csv";
	string output_adj_list_file_name = "adjacency_list_of_undGraph.csv";
	string max_component_nodes_file_name = "nodes(maxComponent).csv";
	string output_max_component_edges = "edges(maxComponent).csv";
	int** adj_matrix = new int*[nodes_count];
	for (int i = 0; i < nodes_count; i++)
		adj_matrix[i] = new int[nodes_count];

	/*adj_matrix = create_adjMatrix(nodes_count, edges_count, nodes_file_name, edges_file_name, output_adj_matrix_file_name);
	create_adjList(nodes_count, adj_matrix, nodes_file_name, output_adj_list_file_name);*/
	makeNewGraph(max_component_nodes_count, edges_count, max_component_nodes_count, nodes_file_name, edges_file_name,
				 max_component_nodes_file_name, output_max_component_edges);

	system("pause");
	return 0;
}