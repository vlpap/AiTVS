#include <stdio.h>
#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
	int N = 4;
	int A[N], B[N], C[N], D[N], F[N];

	for(size_t i = 0; i <= N; i++)
	{
		A[i] = i + 1;
		B[i] = i + 11;
		C[i] = 0;
		D[i] = 0;
		F[i] = 0;

	}
	for(size_t i = 0; i < N; i++)
		cout << A[i] << endl;

	cout << "///////////////////////////////////////////////////" <<endl;
	
	for(size_t i = 0; i < N; i++)
		cout << B[i] << endl;
        
        cout << "///////////////////////////////////////////////////" <<endl;
	
	omp_set_num_threads(3);	
	
	#pragma omp parallel  
	{
		int id, np;
		id = omp_get_thread_num();
		np = omp_get_num_threads();
	
		#pragma omp sections
		{
			#pragma omp section
			{
				for(size_t i = 0; i < N; i++)
					C[i] = A[i] + B[i];
				cout << id << endl;
			}
			#pragma omp section
                        {
                                for(size_t i = 0; i < N; i++)
                                        D[i] = B[i] - A[i];
                                cout << id << endl;
                        }
			#pragma omp section
                        {
                                for(size_t i = 0; i < N; i++)
                                        F[i] = A[i] * B[i];
                                cout << id << endl;
                        }
			
		}

	}
	
	for(size_t i = 0; i < N; i++)
		cout << C[i] << '\t';
	cout << endl;
	
	for(size_t i = 0; i < N; i++)
                cout << D[i] << '\t';
        cout << endl;

	for(size_t i = 0; i < N; i++)
                cout << F[i] << '\t';
        cout << endl;
}
