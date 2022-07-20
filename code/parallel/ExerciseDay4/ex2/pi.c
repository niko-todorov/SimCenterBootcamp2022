#include <stdio.h>
#include <time.h>
#include <math.h>

static long int numSteps = 1000000000;

int main() {

  // perform calculation
  double pi = 0; // , time = 0;
  double dx = 1./numSteps;
  double x  = dx*0.50;

  for (int i=0; i<numSteps; i++) {
    pi += 4./(1.+x*x);
    x += dx;
  }

  pi *= dx;

  printf("PI = %42.40f via 1bil iter OMP\n PI = %42.40f from math.h\n",pi, M_PI); // time
  return 0;
}
