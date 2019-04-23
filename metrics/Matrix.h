#pragma once
#include "Header.h"
class Matrix
{
private:
	int n; // rows' count
	int m; // columns' count
	double** matrix;
public:
	Matrix(int _n, int _m, bool isRead);
	~Matrix();
	void print_to_file(char* file_name);
	friend Matrix degree_centrality(Matrix adj_matr);
};