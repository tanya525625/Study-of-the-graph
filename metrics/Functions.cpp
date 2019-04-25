#include "Header.h"

Matrix degree_centrality(Matrix adj_matr)
{
	int n = adj_matr.n; // count of the nodes
	int curr_degr = 0;
	Matrix degr_centr_matr(1, n);
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

Matrix closeness_centrality(Matrix dist_matr)
{
	int n = dist_matr.n; // count of the nodes
	Matrix clos_centr_matr(1, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dist_matr.matrix[i][j] != 0)
				clos_centr_matr.matrix[0][i] += dist_matr.matrix[i][j];
		}
		clos_centr_matr.matrix[0][i] = round( (n - 1) / clos_centr_matr.matrix[0][i] * 100) / 100;
	}
		
	return clos_centr_matr;
}

Matrix betweenness_centrality(Matrix dist_matr)
{
	int n = dist_matr.n; // count of the nodes
	Matrix betw_centr(1, n);

	return betw_centr;
}