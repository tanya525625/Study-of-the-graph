#pragma once
#include <iostream>
#include <fstream>
using namespace std;

int** create_adjMatrix(int nodes_count, int edges_count);
void create_adjList(int nodes_count, int** adjMatr);