#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int** create_adjMatrix(int nodes_count, int edges_count, string nodes_file_name, string edges_file_name,
	string output_adj_matrix_file_name);
void create_adjList(int nodes_count, int** adj_matrix, string nodes_file_name, string output_adj_list_file_name);
void makeNewGraph(int nodes_count, int edges_count, int max_component_nodes_count, string nodes_file_name, string edges_file_name,
	string max_component_nodes_file_name, string output_max_component_edges);