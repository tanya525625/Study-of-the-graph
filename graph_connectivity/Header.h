#pragma once
#include <iostream>
#include <fstream>
#include "Matrix.h"

using namespace std;

Matrix create_reachabilityMatrix(Matrix adjMatrix);
int* create_nodesList(int nodes_count);