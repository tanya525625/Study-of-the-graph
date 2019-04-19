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
	friend Matrix find_common_neighbors(Matrix adj_matrix);
	friend Matrix find_Jaccard_coeff(Matrix adj_matrix);
	friend Matrix find_union_neighbors(Matrix adj_matrix);
	friend Matrix preferential_attachment(Matrix adj_matrix);
	friend Matrix neighbors_count(Matrix adj_matrix);
	friend Matrix frequency_weighted_common_neighbors(Matrix adj_matrix);
};