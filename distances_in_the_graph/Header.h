#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include "string"
#include "Matrix.h"

using namespace std;

Matrix create_distance_matrix(int nodes_count);
int min(int var1, int var2);
Matrix findEccentricity(Matrix dist_matrix);
int findRadius(Matrix eccentricities);
int findDiameter(Matrix eccentricities);
int* create_nodesList(int nodes_count);
void findCentralNodes(Matrix eccentricities, int r);
void findPeripheralNodes(Matrix eccentricities, int d);
double avgLength(Matrix distMatrix);
double* create_nodes_power_list(int nodes_count, string adj_list_file_name);