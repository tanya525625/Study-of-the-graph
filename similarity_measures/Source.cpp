#include "Header.h"
#include "Matrix.h"

int main()
{
	const int nodes_count = 25;
	Matrix adj_matrix(nodes_count, nodes_count, true);
	char output_common_neighbours [] = "common_neighbours.csv";
	char output_Jacc_coeff[] = "Jaccard_coefficient.csv";
	char output_pref_attach[] = "preferential_attachment.csv";
	char output_freq_weight[] = "frequency_weighted_common_neighbors.csv";

	Matrix common_neigh_matr(nodes_count, nodes_count, false);
	common_neigh_matr = find_common_neighbors(adj_matrix);
	common_neigh_matr.print_to_file(output_common_neighbours);
	find_union_neighbors(adj_matrix);

	Matrix Jacc_coeff(nodes_count, nodes_count, false);
	Jacc_coeff = find_Jaccard_coeff(adj_matrix);
	Jacc_coeff.print_to_file(output_Jacc_coeff);
	
	Matrix pref_attach(nodes_count, nodes_count, false);
	pref_attach = preferential_attachment(adj_matrix);
	pref_attach.print_to_file(output_pref_attach);

	Matrix freq_weight_common_neighbors(nodes_count, nodes_count, false);
	freq_weight_common_neighbors = frequency_weighted_common_neighbors(adj_matrix);
	freq_weight_common_neighbors.print_to_file(output_freq_weight);

	system("pause");
	return 0;
}