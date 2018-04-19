#include <stdio.h>
#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
	int a = 1, b = 10, c = 100;
	
	omp_set_num_threads(2);	
	
	#pragma omp parallel shared(b) private(c)
	{
		int id, np;
		id = omp_get_thread_num();
		np = omp_get_num_threads();
	
		a += 1;	
		b = id;
		c += np;
		
		cout << "id = " << id << '\n' << "a = " << a << '\n' << "b = " << b << endl << "c = " << c << endl;
	}
	cout << "//////////////" << endl << "a = " << a << '\n' << "b = " << b << endl << "c = " << c << endl;
	//printf("a = %d, b = %d, c = %d ");
}
