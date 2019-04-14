#include "Header.h"

// Function for creating a list of all nodes
int* create_nodesList(int nodes_count)
{
	int* nodes_list = new int[nodes_count]; // // Initialization
	ifstream fin_nodes("nodes.csv");
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

Matrix create_reachabilityMatrix(Matrix adjMatrix)
{
	Matrix T(adjMatrix.n, adjMatrix.m, 0); // creating a reachability matrix
	
	for (int i = 0; i <= adjMatrix.n - 1; i++)
	{
		T = adjMatrix.add(T, (adjMatrix.pow(adjMatrix, i)).makeBoolean());
		T = T.makeBoolean();
		Matrix K = adjMatrix.pow(adjMatrix, i).makeBoolean();
	}
	Matrix S(adjMatrix.n, adjMatrix.m, 0); // creating a strong connectivity matrix
	Matrix TT (adjMatrix.n, adjMatrix.m, 0);
	TT = T.transpose(); // transposed matrix T
	S = T.elemMultiplication(T, TT);
	writingToFile(S);
	return S;
}

void writingToFile(Matrix A)
{
	ofstream fout("strong_connectivity_matrix.csv"); // Writing to the file
	if (!fout.is_open())
		cout << "File for strong connectivity matrix wasn't opened" << endl;
	else
	{
		for (int i = 0; i < A.n; i++)
		{
			for (int j = 0; j < A.m; j++)
			{
				fout << A.matrix[i][j] << " ";
			}
			fout << endl;
		}
		fout.close();
		cout << "The creating and writing of strong connectivity matrix is completed" << endl;
	}
}

void ifStronglyConnected(Matrix S)
{
	bool isStronglyConnected = 1;
	for (int i = 0; i < S.n; i++)
		for (int j = 0; j < S.m; j++)
			if (S.matrix[i][j] == 0)
			{
				isStronglyConnected = 0;
				break;
			}
	if (isStronglyConnected == 1)
		cout << "The graph is strongly connected" << endl;
	else
		cout << "The graph isn't strongly connected" << endl;
}

void find_strongConnectivityComponents(Matrix S)
{
	ofstream fout("strong_connectivity_components_of_matrix.csv"); // Writing to the file
	if (!fout.is_open())
		cout << "File for strong connectivity components wasn't opened" << endl;

	int p = 0; // number of strong connectivity components
	int k = 0; // number of nodes added to components
	int i = 0; // current line
	int c = 0; // nodes' number of current component
	bool* addedNodes = new bool[S.n]; // 1 - node was added to component, 0 - else
	int* nodesList = new int[S.n];
	nodesList = create_nodesList(S.n);
	for (int i = 0; i < S.n; i++)
		addedNodes[i] = 0;
	while (k < S.n)
	{
		if (addedNodes[i] == 0)
		{
			c = 0;
			for (int j = 0; j < S.m; j++)
			{
				if ((S.matrix[i][j] == 1) and (addedNodes[j] == 0))
				{
					fout << nodesList[j] << " ";
					addedNodes[j] = 1;
					k++;
					c++;
				}
			}
			addedNodes[i] = 1;
			p++;
			cout << "Nodes number of " << i + 1 << " component is " << c << endl;
			fout << endl;
		}
		i++;
	}
	cout << "The graph has " << p << " strong connectivity components" << endl;
}