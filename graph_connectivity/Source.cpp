#include "Header.h"

int main()
{
	int nodes = 51;
	Matrix adj_matrix(nodes, nodes, 1);
	Matrix S(nodes, nodes, 0);
	S = create_reachabilityMatrix(adj_matrix);
	ifStronglyConnected(S);
	find_strongConnectivityComponents(S);
	
	system("pause");
	return 0;
}