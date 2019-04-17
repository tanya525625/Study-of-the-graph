#include "Header.h"
#include "Matrix.h"

int main()
{
	string adj_matrix_file_name = "adjacency_matrix_of_subgraph.csv";
	string output_dist_matrix_file_name = "distance_matrix.csv";
	string nodes_file_name = "nodes(maxComponent).csv";
	const int nodes_count = 25;
	const int edges_count = 204;
	Matrix dist_matrix(nodes_count, edges_count, true);
	dist_matrix = create_distance_matrix(nodes_count);

	Matrix eccentricities(1, nodes_count, false);
	eccentricities = findEccentricity(dist_matrix);
	int radius = findRadius(eccentricities);
	int diameter = findDiameter(eccentricities);
	cout << "The radius is " << radius << endl; 
	cout << "The diameter is " << diameter << endl;
	findCentralNodes(eccentricities, radius);
	findPeripheralNodes(eccentricities, diameter);
	double avg_length = avgLength(dist_matrix);
	cout << "The average length is " << avg_length << endl;
	system("pause");
	return 0;
}