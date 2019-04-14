#include "Header.h"

Matrix create_reachabilityMatrix(Matrix adjMatrix)
{
	Matrix T(adjMatrix.n, adjMatrix.m, 0); // creating a reachability matrix
	
	for (int i = 0; i <= adjMatrix.n - 1; i++)
	{
		T = adjMatrix.add(T, (adjMatrix.pow(adjMatrix, i)).makeBoolean());
		T = T.makeBoolean();
		Matrix K = adjMatrix.pow(adjMatrix, i).makeBoolean();
		//K.print();
		//cout << endl;
	}
	Matrix S(adjMatrix.n, adjMatrix.m, 0); // creating a strong connectivity matrix
	Matrix TT (adjMatrix.n, adjMatrix.m, 0);
	TT = T.transpose(); // transposed matrix T
	S = T.elemMultiplication(T, TT);
	//S.print();
	writingToFile(S);
	return S;
}

void writingToFile(Matrix A)
{
	ofstream fout("strong_connectivity_matrix.csv"); // Writing to the file
	if (!fout.is_open())
		cout << "File for strong connectivity matrix wasn't opened" << endl;
	else
	{
		for (int i = 0; i < A.n; i++)
		{
			for (int j = 0; j < A.m; j++)
			{
				fout << A.matrix[i][j] << " ";
			}
			fout << endl;
		}
		fout.close();
		cout << "The creating and writing of strong connectivity matrix is completed" << endl;
	}
}

void ifStronglyConnected(Matrix S)
{
	bool isStronglyConnected = 1;
	for (int i = 0; i < S.n; i++)
		for (int j = 0; j < S.m; j++)
			if (S.matrix[i][j] == 0)
			{
				isStronglyConnected = 0;
				break;
			}
	if (isStronglyConnected == 1)
		cout << "The graph is strongly connected" << endl;
	else
		cout << "The graph isn't strongly connected" << endl;
}