#include "Header.h"

void find_common_neighbors(Matrix adj_matrix)
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
				//s.matrix[row2_index][j] += 1;
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
	
	s.print_to_file();
}
