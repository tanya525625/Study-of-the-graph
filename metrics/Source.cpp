#include "Header.h"
#include "Matrix.h"

int main()
{
	const int nodes_count = 25;
	Matrix adj_matrix(nodes_count, nodes_count, true);
	char output_degree_centrality[] = "degree_centrality.csv";

	Matrix degr_centr_matr(1, nodes_count, false);
	degr_centr_matr = degree_centrality(adj_matrix);
	degr_centr_matr.print_to_file(output_degree_centrality);


	system("pause");
	return 0; 
}