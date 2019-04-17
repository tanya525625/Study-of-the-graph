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
	friend Matrix create_distance_matrix(int nodes_count);
	friend Matrix findEccentricity(Matrix dist_matrix);
	friend int findRadius(Matrix eccentricities);
	friend int findDiameter(Matrix eccentricities);
	friend void findCentralNodes(Matrix eccentricities, int r);
	friend void findPeripheralNodes(Matrix eccentricities, int d);
	friend double avgLength(Matrix distMatrix);
};

