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
	int N=5;
	int a[N];
	
	if (id == 0)
	{
		for (size_t i = 0; i < N; i++)
			a[i]=i+3;
	}	
	
	MPI_Bcast(&a, N, MPI_INT, 0, MPI_COMM_WORLD);
	
	for (size_t i = 0; i < N; i++)
	{
		cout<<"a"<<i<<"="<<a[i]<<'\t'<<"id="<<id<<endl;
	}
	
	MPI_Finalize();	
}



