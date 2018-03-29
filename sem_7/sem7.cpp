#include <stdio.h>
#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char *argv[])
{
	
	MPI_Init( &argc, &argv);

	int id, np;

	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	MPI_Comm_size(MPI_COMM_WORLD, &np);
	MPI_Status status;
	MPI_Request request;

	int sum = 0;
	int N = 5;
	int A[N][N], B[N][N], C[N][N], res[N][N];
	
	for(size_t i = 0; i < N; i++)
		for(size_t j = 0; j < N; j++)
		{
			A[i][j] = j + 1;
			B[i][j] = i + 1;
			C[i][j] = 0;
		}
	for(size_t i = id; i < N; i +=np)
		for(size_t j = 0; j < N; j++)
                	for(size_t k = 0; k < N; k++)
			{
				C[i][j] += A[i][k] * B[k][j]; 
			}
	MPI_Reduce(&C[0], &res[0], N*N, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if (id == 0)
	{
		for(size_t i = 0; i < N; i++)
		{
        		for(size_t j = 0; j < N; j++)
				cout << res[i][j] << '\t';
			cout << endl;
		}	
	}	
	MPI_Finalize();
}





