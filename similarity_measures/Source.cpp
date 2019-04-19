#include "Header.h"
#include "Matrix.h"

int main()
{
	const int nodes_count = 25;
	Matrix adj_matrix(nodes_count, nodes_count, true);
	string output_common_neighbours = "common_neighbours.csv";
	
	Matrix s(nodes_count, nodes_count, false);
	find_common_neighbors(adj_matrix);

	system("pause");
	return 0;
}