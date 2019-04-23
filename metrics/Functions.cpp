#include "Header.h"

Matrix degree_centrality(Matrix adj_matr)
{
	int n = adj_matr.n; // count of the nodes
	int curr_degr = 0;
	Matrix degr_centr_matr(1, n, false);
	for (int i = 0; i < n; i++)
	{
		curr_degr = 0;
		for (int j = 0; j < n; j++)
		{
			if (adj_matr.matrix[i][j] == 1)
				curr_degr++;
		}
		degr_centr_matr.matrix[0][i] = curr_degr/double(n);
	}

	return degr_centr_matr;
}