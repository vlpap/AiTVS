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

	int itest;
	int sum = 0;
	int N = 5, b[N], bMax[N];
	
	int a = id * 5;
	MPI_Reduce(&a, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if (id == 0)
		cout << "SUM = " << sum << endl;
	
	for (size_t i = 0; i<N; i++)
		b[i] = id * i + 1;
	
	MPI_Allreduce(&b[0], &bMax[0], N, MPI_INT, MPI_MAX, MPI_COMM_WORLD);
	for (size_t i = 0; i<N; i++)
		cout << "id = " << id << ":" << "bMax" << i << " = " << bMax[i] << endl;
	MPI_Finalize();
}





