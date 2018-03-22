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

	int N = 10;
	int a[N];
	int itest;
	
	if (id == 0)
	{
		for (int i = 0; i < N; i++)
			a[i] = i + 1;
		//MPI_Send(&a[0], N, MPI_INT, np-1, 333, MPI_COMM_WORLD);
		MPI_Isend(&a[0], N, MPI_INT, np-1, 333, MPI_COMM_WORLD, &request);
		MPI_Test(&request, &itest, &status);
		cout << itest << endl;
	}	

	if (id == np - 1)
	{
		//MPI_Recv(&a[0], N, MPI_INT, 0, 333, MPI_COMM_WORLD, &status);
		MPI_Irecv(&a[0], N, MPI_INT, 0, 333, MPI_COMM_WORLD,&request);
		MPI_Wait(&request, &status);
		for (int i = 0; i < N; i++)
			cout << "i = " << i << " a[i] = " << a[i]<< endl;
	}

	MPI_Finalize();
}





