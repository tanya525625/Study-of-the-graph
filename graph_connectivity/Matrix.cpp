#include "Header.h"

Matrix::Matrix(int _n, int _m, bool isRead)
{
	n = _n; m = _m;
	ifstream fin("adjacency_matrix.csv");
	if (!fin.is_open())
	{
		cout << "File wasn't opened";
	}
	else
	{
		matrix = new int*[n];
		for (int i = 0; i < n; i++)
		{
			matrix[i] = new int[m];
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (isRead == 1)
					fin >> matrix[i][j];
				else
					matrix[i][j] = 0;
				
		fin.close();
	}
}

Matrix::~Matrix()
{
}

void Matrix::print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

}

//multiplication of two matrices
Matrix operator *(Matrix &a1, Matrix &a2)
{
	Matrix res(a1.n, a2.m, 0);

	if (a1.m == a2.n)
	{
		for (int i = 0; i < a1.n; i++)
		{
			for (int j = 0; j < a2.m; j++)
			{
				for (int k = 0; k < a2.n; k++)
				{
					res.matrix[i][j] += a1.matrix[i][k] * a2.matrix[k][j];
				}
			}
		}

	}
	else
	{
		cout << "ERROR. Matrices can not be multiplied" << endl;
	}
	return res;
}

// addition of two matrices
Matrix Matrix::add (Matrix a1, Matrix a2)
{
	Matrix res(a1.n, a2.m, 0);

	if ((a1.n == a2.n) and (a1.m == a2.m)) 
	{
		for (int i = 0; i < a1.n; i++)
		{
			for (int j = 0; j < a1.m; j++)
			{
				res.matrix[i][j] = a1.matrix[i][j] + a2.matrix[i][j];
			}
		}
	}
	else
	{
		cout << "ERROR. Matrices have different dimensions " << endl;
	}
	return res;
}

// pow of the matrix
Matrix Matrix::pow(Matrix A, int k)
{
	Matrix res = createIdentArr(A.n);
	for (int i = 0; i < k; i++)
	{
		res = res * A;
	}
	return res;
}

// creating an identity matrix
Matrix Matrix::createIdentArr(int n)
{
	Matrix identArr(n, n, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j)
				identArr.matrix[i][j] = 1;
	return identArr;
}

Matrix Matrix::transpose()
{
	Matrix tmpMatrix(m, n, 0);

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			tmpMatrix.matrix[i][j] = matrix[j][i];
	return tmpMatrix;
}

// elementwise multiplication of two matrices
Matrix Matrix::elemMultiplication(Matrix a1, Matrix a2)
{
	Matrix res(n, m, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res.matrix[i][j] = a1.matrix[i][j] * a2.matrix[i][j];
	return res;
}

// creating a binary matrix
Matrix Matrix::makeBoolean()
{
	Matrix res(n, m, 0);
	res = *this;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if ((*this).matrix[i][j] > 0)
				res.matrix[i][j] = 1;
			else
				res.matrix[i][j] = 0;
	return res;
}