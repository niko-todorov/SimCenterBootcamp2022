#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
long MAXINT = 100000000;
void main(int argc, char**argv)
{
	long MAXINT = 100000000;
	if (argc>0) MAXINT = atol(argv[1]);
	int i;
	double x = 0.0, pi = 0.0, dx = 1.0/MAXINT;
	int nt = omp_get_num_threads();
#pragma omp parallel 
	{
		//int nt = omp_get_num_threads();
#pragma omp for reduction(+:pi) //sum
		for (i=0; i<MAXINT; i++)
		{
			x = i*dx;
			pi += 4.0/(1.0+x*x); //sum
		}
	}
	pi *= dx;
  	printf("PI = %22.20f OpenMP calculated with %d iterations, %d threads\nPI = %22.20f from math.h definition\nDIFF %22.20f",pi, MAXINT, M_PI,pi-M_PI);
}
