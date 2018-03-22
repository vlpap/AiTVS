#include <stdio.h>
#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char *argv[])
{
	
	int size, rank;
    	MPI_Init( &argc, &argv);

	int id, np;

	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	MPI_Comm_size(MPI_COMM_WORLD, &np);

	int N = 12;
	int del = N/np;
	int i0 = del*id;
	int imax = i0 + del;

	int a[N], b[N], c[N], i;
	
	for (i = 0; i < N; i++)
	{
		a[i] = i;
		b[i] = i+10;
	}

	//if (id == np - 1)
	//	imax = N;

//	if (id == np-1)
//		imax=N;
	
	//for (int i = i0; i < im; i++)
	for (int i = id; i < N; i += np)
	{
		c[i] = a[i] + b[i];
		cout << i <<" " << id <<" "<< c[i] << endl;
	}

	MPI_Finalize();
}





