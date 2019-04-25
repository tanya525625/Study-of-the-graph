#pragma once
#include <iostream>
#include <fstream>
#include "Matrix.h"

using namespace std;

Matrix degree_centrality(Matrix adj_matr);
Matrix closeness_centrality(Matrix dist_matr);