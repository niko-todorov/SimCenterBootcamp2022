#include <stdio.h>
#include <time.h>
#include <math.h>
#include <omp.h>

static long int numSteps = 10000000;

int main() {

// perform calculation
double pi = 0;
double dx = 1./numSteps;
double x  = dx;

#pragma omp parallel for
  for (int i=0; i<numSteps; i++) {
    pi += 4./(1.+x*x);
    x += i*dx;
  }

#pragma omp critical
{ //pi += sum * step;
  pi *= dx;
}
  printf("PI = %16.14f Difference from math.h definition %16.14f \n",pi, pi-M_PI);
  return 0;
}
