#include "Header.h"
#include "Matrix.h"

int main()
{
	char input_adj_matrix[] = "adjacency_matrix_of_subgraph.csv";
	char input_dist_matrix[] = "distance_matrix.csv";

	char output_degree_centrality[] = "degree_centrality.csv";
	char output_clos_centr[] = "closeness_centrality.csv";

	const int nodes_count = 25;
	Matrix adj_matrix(nodes_count, nodes_count, input_adj_matrix);
	Matrix dist_matrix(nodes_count, nodes_count, input_dist_matrix);
	

	Matrix degr_centr_matr(1, nodes_count);
	degr_centr_matr = degree_centrality(adj_matrix);
	degr_centr_matr.print_to_file(output_degree_centrality);

	Matrix clos_centr_matr(1, nodes_count);
	clos_centr_matr = closeness_centrality(dist_matrix);
	clos_centr_matr.print_to_file(output_clos_centr);


	system("pause");
	return 0; 
}