#include "Header.h"

Matrix::Matrix(int _n, int _m, bool isRead)
{
	n = _n; m = _m;
	ifstream fin("adjacency_matrix_of_subgraph.csv");
	if (!fin.is_open())
	{
		cout << "File wasn't opened" << endl;
	}
	else
	{
		matrix = new double*[n];
		for (int i = 0; i < n; i++)
		{
			matrix[i] = new double[m];
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

void Matrix::print_to_file(char* file_name)
{
	//string output_common_neighbours = "common_neighbours.csv";
	ofstream fout(file_name); // Writing to the file

	if (!fout.is_open())
		cout << "File for writing wasn't opened" << endl;
	else
	{
		for (int i = 0; i < (*this).n; i++)
		{
			for (int j = 0; j < (*this).m; j++)
			{
				fout << (*this).matrix[i][j] << "\t";
			}
			fout << endl;
		}
		fout.close();
		cout << "The writing of matrix to file " << file_name  <<" is completed" << endl;
	}
}
