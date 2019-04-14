#pragma once
class Matrix
{
private:
	int n; // number of lines
	int m; // number of columns
	int** matrix ;
public:
	void print();
	Matrix(int _n, int _m, bool isRead);
	~Matrix();
	friend Matrix operator *(Matrix &a1, Matrix &a2);
	Matrix pow(Matrix A, int k); 
	friend Matrix create_reachabilityMatrix(Matrix adjMatrix);
	Matrix createIdentArr(int n);
	Matrix add(Matrix a1, Matrix a2); // addition
	Matrix transpose();
	Matrix elemMultiplication(Matrix a1, Matrix a2);
	Matrix makeBoolean();
	friend void writingToFile(Matrix A);
	friend void ifStronglyConnected(Matrix S);
	friend void find_strongConnectivityComponents(Matrix S);
};

