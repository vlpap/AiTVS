#include <stdio.h>
#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
	int N = 10, i;
	int A[N], B[N], C[N];

	for(i = 0; i <= N; i++)
	{
		A[i] = i + 1;
		B[i] = i + 11;
	}
	omp_set_num_threads(13);	
	
	#pragma omp parallel private(i) shared(A,B,C,N) 
	{
		int id, np;
		id = omp_get_thread_num();
		np = omp_get_num_threads();
	
		#pragma omp for
		for(size_t i = 0; i <= N; i++)
		{
			C[i] = A[i] + B[i];
			cout << "id = " << id << " C[" << i << "] = " << C[i] << endl << endl;
		}
	}
}
