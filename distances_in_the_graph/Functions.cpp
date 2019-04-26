#include "Header.h"

Matrix create_distance_matrix(int nodes_count)
{
	Matrix adj_matrix(nodes_count, nodes_count, true);
	for (int i = 0; i < nodes_count; i++)
		for (int j = 0; j < nodes_count; j++)
		{
			if (adj_matrix.matrix[i][j] == 0)
				adj_matrix.matrix[i][j] = nodes_count;
			if (i == j)
				adj_matrix.matrix[i][j] = 0;
		}
			
	for (int k = 0; k < nodes_count; k++)
		for (int i = 0; i < nodes_count; i++)
			for (int j = 0; j < nodes_count; j++)
				adj_matrix.matrix[i][j] = min(adj_matrix.matrix[i][j], adj_matrix.matrix[i][k] + adj_matrix.matrix[k][j]);
	adj_matrix.print_to_file();
	return adj_matrix;
}

int min(int var1, int var2)
{
	if (var1 > var2)
		return var2;
	else
		return var1;
}

Matrix findEccentricity(Matrix dist_matrix)
{
	int maxDist = 0;
	Matrix eccentricities(1, dist_matrix.n, false);
	for (int i = 0; i < dist_matrix.n; i++)
	{
		for (int j = 0; j < dist_matrix.n; j++)
		{
			if (dist_matrix.matrix[i][j] > maxDist)
				maxDist = dist_matrix.matrix[i][j];
		}
		eccentricities.matrix[0][i] = maxDist;
		maxDist = 0;
	}
	return eccentricities;
}

int findRadius(Matrix eccentricities)
{
	int r = eccentricities.m; // radius
	for (int i = 0; i < eccentricities.m; i++)
		if (eccentricities.matrix[0][i] < r)
		r = eccentricities.matrix[0][i];

	return r;
}

int findDiameter(Matrix eccentricities)
{
	int d = 0; // diameter
	for (int i = 0; i < eccentricities.m; i++)
		if (eccentricities.matrix[0][i] > d)
			d = eccentricities.matrix[0][i];

	return d;
}

// Function for creating a list of all nodes
int* create_nodesList(int nodes_count)
{
	int* nodes_list = new int[nodes_count]; // // Initialization
	ifstream fin_nodes("nodes(maxComponent).csv");
	if (!fin_nodes.is_open())
		cout << "File with list of nodes wasn't opened" << endl;
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

void findCentralNodes(Matrix eccentricities, int r)
{
	int* nodes_list = new int[eccentricities.m];
	nodes_list = create_nodesList(eccentricities.m);
	cout << "Central nodes are ";
	for (int i = 0; i < eccentricities.m; i++)
	{
		if (eccentricities.matrix[0][i] == r)
			cout << nodes_list[i] << "\t";
	}
	cout << endl;
}

void findPeripheralNodes(Matrix eccentricities, int d)
{
	int* nodes_list = new int[eccentricities.m];
	nodes_list = create_nodesList(eccentricities.m);
	cout << "Peripheral nodes are ";
	for (int i = 0; i < eccentricities.m; i++)
	{
		if (eccentricities.matrix[0][i] == d)
			cout << nodes_list[i] << "\t";
	}
	cout << endl;
}

double avgLength(Matrix distMatrix)
{
	double avgLength = 0;
	for (int i = 0; i < distMatrix.n; i++)
		for (int j = 0; j < distMatrix.n; j++)
			avgLength += distMatrix.matrix[i][j];
	avgLength = avgLength / (distMatrix.n*distMatrix.n);
	return avgLength;
}

double* create_nodes_power_list(int nodes_count, string adj_list_file_name)
{
	ifstream fin(adj_list_file_name);
	int curr_node; // current node from the file
	int* temp_power_list = new int[nodes_count];
	string curr_row; // current row from the file
	int pow = 0; // power of the current node
	int max_pow = 0;
	char c; // curr char from file
	for (int i = 0; i < nodes_count; i++)
	{
		fin >> curr_node;
		getline(fin, curr_row, '\n');
		int curr_row_size = curr_row.size();
		for (int j = 0; j < curr_row_size; j++)
			if (curr_row[j] == ' ') 
				pow++;
		
		pow -= 1; // there is an extra space after reading the first node
		temp_power_list[i] = pow;
		if (pow > max_pow)
			max_pow = pow;
		pow = 0;
	}

	double* power_list = new double[max_pow+1];
	for (int i = 0; i < max_pow + 1; i++)
	{
		power_list[i] = 0;
	}
	for (int i = 0; i < nodes_count; i++)  // creating array, where values are count of the nodes 
	{									   // with current power (index of array)
		power_list[temp_power_list[i]] += 1;
	}

	double avg_node_degree = 0;

	// finding avg_node_degree
	for (int i = 0; i < max_pow + 1; i++)
	{
		avg_node_degree += i * power_list[i];
	}
	avg_node_degree /= nodes_count;

	cout << "The average nodes' degree is " << avg_node_degree << endl;

	for (int i = 0; i < max_pow + 1; i++)
	{
		power_list[i] /= nodes_count;
	}

	cout << "Power list:  " << endl;
	for (int i = 0; i < max_pow + 1; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (int i = 0; i < max_pow + 1; i++)
	{
		cout << power_list[i] << "\t";
	}
	cout << endl;

	
	return power_list;
}
