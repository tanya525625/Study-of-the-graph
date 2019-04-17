#include "Header.h"

// Function for creating a list of all nodes
int* create_nodesList(int nodes_count, string file_name) 
{
	int* nodes_list = new int[nodes_count]; // // Initialization
	ifstream fin_nodes(file_name);
	if (!fin_nodes.is_open())
		cout << "File with list of nodes wasn't opened";
	else
	{
		int curr_node;
		for (int i = 0; i < nodes_count; i++) 
		{
			fin_nodes >> curr_node; // Reading from the file
			nodes_list[i] = curr_node;
		}
		fin_nodes.close();
	}
	return nodes_list;
}

// Function for creating adjacency_matrix
int** create_adjMatrix(int nodes_count, int edges_count, string nodes_file_name, string edges_file_name,
						string output_adj_matrix_file_name)
{
	ifstream fin_edges(edges_file_name);
	int* nodes_list = new int[nodes_count]; // Initialization
	nodes_list = create_nodesList(nodes_count, nodes_file_name);
	int** matrix = new int*[nodes_count];
	for (int i = 0; i < nodes_count; i++)
		matrix[i] = new int[nodes_count];
	for (int i = 0; i < nodes_count; i++)
	{
		for (int j = 0; j < nodes_count; j++)
		{
			matrix[i][j] = 0;
		}
	}

	if (!fin_edges.is_open())
		cout << "File with list of edges wasn't opened";
	else
	{
		int curr_source;
		int curr_target;
		int source_index;
		int target_index;

		for (int i = 0; i < edges_count; i++) // Creating adjacency matrix
		{
			fin_edges >> curr_source;
			fin_edges >> curr_target;
			for (int j = 0; j < nodes_count; j++) // Index definition of source and target 
			{									  // Matching with the nodes' list 
				if (nodes_list[j] == curr_source)
					source_index = j;
				if (nodes_list[j] == curr_target)
					target_index = j;
			}
			matrix[source_index][target_index] = 1;
		}
	}
	fin_edges.close();

	ofstream fout_adjMatrix(output_adj_matrix_file_name); // Writing to the file
	if (!fout_adjMatrix.is_open())
		cout << "File for writing of adjacency_matrix wasn't opened" << endl;
	else
	{
		for (int i = 0; i < nodes_count; i++) 
		{
			for (int j = 0; j < nodes_count; j++) 
			{
				fout_adjMatrix << matrix[i][j] << " ";
			}
			fout_adjMatrix << endl;
		}
		fout_adjMatrix.close();
		cout << "The creating and writing of adjacency matrix is completed" << endl;
	}

	return matrix;
}

// Function for creating adjacency_list
void create_adjList(int nodes_count, int** adj_matrix, string nodes_file_name, string output_adj_list_file_name)
{
	int* nodes_list = new int[nodes_count];
	nodes_list = create_nodesList(nodes_count, nodes_file_name);

	ofstream fout_adjList(output_adj_list_file_name); // // Writing to the file
	if (!fout_adjList.is_open())
		cout << "File for writing of adjacency list wasn't opened" << endl;
	else
	{ 
		for (int i = 0; i < nodes_count; i++) 
		{	
			fout_adjList << nodes_list[i] << ": ";
			for (int j = 0; j < nodes_count; j++) 
			{
				if (adj_matrix[i][j] == 1)
					fout_adjList << nodes_list[j] << " ";	
			}
			fout_adjList << endl;
		}
		fout_adjList.close();
		cout << "The creating and writing adjacency list is completed" << endl;
	}
}

void makeNewGraph(int nodes_count, int edges_count, int max_component_nodes_count, string nodes_file_name, string edges_file_name,
			string max_component_nodes_file_name, string output_max_component_edges)
{
	//int* nodes_list = new int[nodes_count]; // Initialization
	//nodes_list = create_nodesList(nodes_count, nodes_file_name);
	int* max_component_nodes_list = new int[max_component_nodes_count]; 
	max_component_nodes_list = create_nodesList(nodes_count, max_component_nodes_file_name);
	ifstream fin(edges_file_name);
	ofstream fout(output_max_component_edges); // Writing to the file
	if (!fout.is_open())
		cout << "File for writing edges of the graph's max component wasn't opened" << endl;
	else
	{
		int source;
		int target;
		int pre_source;
		int pre_target;
		int i = 0;
		int j = 0; 
		bool isAdded = 0;
		while (j < edges_count)
		{
			if (i > nodes_count)
				i = nodes_count - 1;
			fin >> source;
			fin >> target;
			j++;
			if (source == max_component_nodes_list[i])
			{
				if (i > nodes_count)
					i = nodes_count - 1;
				fout << source << " ";
				fout << target << endl;
				while (source == max_component_nodes_list[i] and j < edges_count)
				{
					if (i > nodes_count)
						i = nodes_count - 1;
					fin >> source;
					fin >> target;
					pre_source = source;
					pre_target = target;
					j++;
					if (source == max_component_nodes_list[i])
					{
						fout << source << " ";
						fout << target << endl;
						pre_source = source;
						pre_target = target;
					}
					else
					{
						i++;
						if (pre_source == max_component_nodes_list[i])
						{
							fout << pre_source << " ";
							fout << pre_target << endl;
						}
					}
				}
			}
		}
		fout.close();
		cout << "The creating and writing of new graph's max component is completed" << endl;
	}

}