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

//Matrix betweenness_centrality(Matrix dist_matr)
//{
//	int n = dist_matr.n; // count of the nodes
//	Matrix betw_centr_matr(1, n);
//	Matrix sigma(1, n);
//	Matrix d(1, n);
//	for (int s = 0; s < n; s++) // for each node
//	{
//		stack < double > S;
//		list < double > P;
//		for (int w = 0; w < n; w++)
//		{
//			P.append
//			sigma.matrix[0][j] = 0;
//			sigma.matrix[0][i] = 1;
//			d.matrix[0][j] = -1;
//			d.matrix[0][i] = 0;
//		}
// 		queue < double > Q; // queue
//		Q.push(i);
//		while (!Q.empty())
//		{
//			double v = Q.front();
//			Q.pop();
//			S.push(v);
//
//		}
//	}
//
//	return betw_centr_matr;
//}

//Matrix eigenvector_centrality(Matrix adj_matrix)
//{
//	int n = adj_matrix.n;
//	Matrix x(1, n);
//	double sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		x.matrix[0][i] = 1 / n;
//		sum += x.matrix[0][i];
//	}
//	// normalize starting vector
//
//}