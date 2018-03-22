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
	int a, b, c;
	if (id == 0)
	{
		a = 10;
		MPI_Isend(&a, 1, MPI_INT, 1, 444, MPI_COMM_WORLD, &request);
		MPI_Test(&request, &itest, &status);
		cout << itest << endl;
	}	
	
	if (id == 1)
	{
		b = 20;
		MPI_Sendrecv(&b, 1, MPI_INT, 2, 333, &a, 1, MPI_INT, 0, 444, MPI_COMM_WORLD, &status);
		cout << "a=" << a << endl;
	}
	
	if (id == 2)
	{
		
		MPI_Irecv(&b, 1, MPI_INT, 1, 333, MPI_COMM_WORLD,&request);
		MPI_Wait(&request, &status);
		cout << "b=" << b << endl;
	}

	MPI_Finalize();
}





