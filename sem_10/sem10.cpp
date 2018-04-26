#include <stdio.h>
#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
	int N = 7;
	int A[N][N], B[N][N], C[N][N];

	for(size_t i = 0; i <= N; i++)
	{
		for(size_t j = 0; j < N; j++)
		{
			A[i][j] = j + 1;
			B[i][j] = i + 1;
			C[i][j] = 0;
		}
	}
	for(size_t i = 0; i < N; i++)
	{
                for(size_t j = 0; j < N; j++)
                {
                        cout << A[i][j] << '\t';
                }
		cout << endl;
	}
	cout << "///////////////////////////////////////////////////" <<endl;
	for(size_t i = 0; i < N; i++)
        {
		for(size_t j = 0; j < N; j++)
                {
                	cout << B[i][j] << '\t';
                }
                cout << endl;
        }

	cout << "///////////////////////////////////////////////////" <<endl;
	
	omp_set_num_threads(13);	
	
	#pragma omp parallel //private(i) shared(A,B,C,N) 
	{
		int id, np;
		id = omp_get_thread_num();
		np = omp_get_num_threads();
	
		#pragma omp for
		for(size_t i = 0; i < N; i ++)
			for(size_t j = 0; j < N; j++)
				for(size_t k = 0; k < N; k++)
					C[i][j] += A[i][k] * B[k][j];
	}	
	for(size_t i = 0; i < N; i++)
	{
		for(size_t j = 0; j < N; j++)
			cout << C[i][j] << '\t';
		cout << endl;
	}
}
