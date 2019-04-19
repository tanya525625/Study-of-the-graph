#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "Matrix.h"

using namespace std;

Matrix find_union_neighbors(Matrix adj_matrix);
Matrix find_Jaccard_coeff(Matrix adj_matrix);
Matrix preferential_attachment(Matrix adj_matrix);
Matrix frequency_weighted_common_neighbors(Matrix adj_matrix);