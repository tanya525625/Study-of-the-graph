#include "Header.h"

Matrix find_common_neighbors(Matrix adj_matrix)
{
	int n = adj_matrix.n; // nodes' count
	Matrix s(n, n, false); // matrix of common neighbors' count 
	int row1_index = 0;
	int row2_index = 0;
	int k = 0; // number of viewed nodes 
	while ((row1_index < n) and (row2_index < n))
	{
		for (int j = 0; j < n; j++)
		{
			if ((adj_matrix.matrix[row1_index][j] == adj_matrix.matrix[row2_index][j]) and (adj_matrix.matrix[row1_index][j] == 1))
			{
				s.matrix[row1_index][row2_index] += 1;
			}
		}
		
		if (row2_index == n - 1)
		{
			k++;
			row1_index = k;
			row2_index = -1;
		}
		row2_index++;
	}
	return s;
}

Matrix find_union_neighbors(Matrix adj_matrix)
{
	int n = adj_matrix.n; // nodes' count;
	Matrix s(n, n, false); // matrix of union neighbors
	int row1_index = 0;
	int row2_index = 0;
	
	int k = 0; // number of viewed nodes 
	while ((row1_index < n) and (row2_index < n))
	{
		for (int j = 0; j < n; j++)
		{
			if ((adj_matrix.matrix[row1_index][j] == 1) or (adj_matrix.matrix[row2_index][j] == 1))
			{
				s.matrix[row1_index][row2_index] += 1;
			}
		}
		if (row2_index == n - 1)
		{
			k++;
			row1_index = k;
			row2_index = -1;
		}
		row2_index++;
	}

	return s;
}

Matrix find_Jaccard_coeff(Matrix adj_matrix)
{
	int n = adj_matrix.n; // nodes' count;
	Matrix s(n, n, false); // matrix with Jaccard’s coefficients
	Matrix intersection_nodes(n, n, false); // matrix of common neighbors
	intersection_nodes = find_common_neighbors(adj_matrix);
	s = find_union_neighbors(adj_matrix);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			s.matrix[i][j] = round(intersection_nodes.matrix[i][j] / s.matrix[i][j] * 1000)/1000;

	return s;
}

Matrix neighbors_count(Matrix adj_matrix)
{
	int n = adj_matrix.n; // nodes' count;
	Matrix neighbours_count(1, n, false);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (adj_matrix.matrix[i][j] == 1)
				neighbours_count.matrix[0][i] += 1;
	return neighbours_count;
}

Matrix preferential_attachment(Matrix adj_matrix)
{
	int n = adj_matrix.n; // nodes' count;
	Matrix s(n, n, false); // matrix of preferential_attachment
	Matrix neighbors_count_matr(1, n, false);
	neighbors_count_matr = neighbors_count(adj_matrix);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			s.matrix[i][j] = neighbors_count_matr.matrix[0][i] * neighbors_count_matr.matrix[0][j];


	//for (int i = 0; i < n; i++)
	//{

	//	cout << neighbors_count_matr.matrix[0][i] << endl;
	//}
	return s;
}

Matrix frequency_weighted_common_neighbors(Matrix adj_matrix)
{
	int n = adj_matrix.n; // nodes' count;
	Matrix neighbours_count_matr(1, n, false);
	neighbours_count_matr = neighbors_count(adj_matrix);
	Matrix s(n, n, false); // frequency weighted common neighbors matrix
	int row1_index = 0;
	int row2_index = 0;

	int k = 0; // number of viewed nodes 
	while ((row1_index < n) and (row2_index < n))
	{
		for (int j = 0; j < n; j++)
		{
			if ((adj_matrix.matrix[row1_index][j] == adj_matrix.matrix[row2_index][j]) and (adj_matrix.matrix[row1_index][j] == 1))
			{
				s.matrix[row1_index][row2_index] += round(1/log(neighbours_count_matr.matrix[0][j])*1000)/1000;
			}
		}

		if (row2_index == n - 1)
		{
			k++;
			row1_index = k;
			row2_index = -1;
		}
		row2_index++;
	}
	return s;
}