#include <stdio.h>
#include <iostream>
#include <omp.h>

using namespace std;
double f(double x)
{
    return x*x;
}

int main()
{
	int n = 23;
	double res = 0, a = 1, b = 2, x = 0;
    	double h = (b-a)/(n-1);

	omp_set_num_threads(3);	
	
	#pragma omp parallel reduction (+ : res)
	{	
		#pragma omp for //reduction (+ : res)
		for(int i = 1; i < n-1; i++)
		{
			res += f(a + i * h);
		}
	}
		res += f(a)/2;
		res += f(a + (n-1) * h)/2;			
		res *= h;
	
	cout << "res = " << res << endl;
}	
