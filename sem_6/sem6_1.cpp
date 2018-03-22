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
	int N = 20, a[N];
	int del = N/np;
	int i0 = del * id;
	int iMax = i0 + del;
	int tempSum = 0;
	
	for (size_t i = 0; i < N; i++)
		a[i] = i;
	
	for (size_t i = id; i < N; i += np)
		tempSum += a[i];
	cout <<"id = "<< id <<" : "<< tempSum << endl;	
	MPI_Reduce(&tempSum, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

	if (id == 0)
		cout <<"sum = " << sum << endl;		
	
	MPI_Finalize();
}





