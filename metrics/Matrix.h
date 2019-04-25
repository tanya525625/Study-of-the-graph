#pragma once
#include "Header.h"
class Matrix
{
private:
	int n; // rows' count
	int m; // columns' count
	double** matrix;
public:
	Matrix(int _n, int _m, char* file_name);
	Matrix(int _n, int _m);
	~Matrix();
	void print_to_file(char* file_name);
	friend Matrix degree_centrality(Matrix adj_matr);
	friend Matrix closeness_centrality(Matrix adj_matr);
	friend Matrix betweenness_centrality(Matrix dist_matr);
};