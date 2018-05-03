#include <stdio.h>
#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
	int N = 23;
	int A[N];

	for(int i = 0; i < N; i++)
		A[i] = i + 1;
	
	for(size_t i = 0; i < N; i++)
		cout << A[i] << endl;

	cout << "///////////////////////////////////////////////////" <<endl;
		
	omp_set_num_threads(13);	
	
	int s = 0, m = 0;
		
	#pragma omp parallel reduction( + : s)
	{
		int id = omp_get_thread_num();
		int np = omp_get_num_threads();

		#pragma omp for //reduction( + : s)
		for(int i = 0; i < N; i++)
		{
			s += A[i];
		}	
		
		//cout << "tempS " << s << endl;
		
		#pragma omp critical
			m++;
	
		#pragma omp single
			cout << "id = " << id << " np = " << np << endl;
	
	}
	
	cout << "M = " << m << endl;
}	
