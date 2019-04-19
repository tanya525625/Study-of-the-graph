#pragma once
#include "Header.h"
class Matrix
{
private:
	int n; // rows' count
	int m; // columns' count
	int** matrix;
public:
	Matrix(int _n, int _m, bool isRead);
	~Matrix();
	void print_to_file();
	friend void find_common_neighbors(Matrix adj_matrix);
};