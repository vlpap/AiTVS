#include <stdio.h>
#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
	cout << "HI" << endl;
	
	//omp_set_num_threads(4);	
	
	#pragma omp parallel
	{
		int id, np;
		id = omp_get_thread_num();
		np = omp_get_num_threads();
	
	
		cout << "parallel block" << '\t' << "id = " << id << endl;
		if (id == 0)
		{
			cout << "np= " << np << endl;
		}	
	}
	#pragma omp parallel num_threads(2)
	{
		cout << "BB" << endl;
	}
}
