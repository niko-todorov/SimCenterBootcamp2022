#include <stdio.h>
#include <time.h>
#include <math.h>

static long int n = 1000000000; // 1bil

int main() {

  // perform calculation
  double pi = 0;
  double dx = 1./n;
  double x  = dx*0.50;
  double _pi= 4.*atan(1.);

  printf("PI = %42.40f const from math.h\nPI = %42.40f empirically from 4*atan(1)\n",M_PI,_pi);

  for (int i=0; i<n; i++) {
    pi += 4./(1.+x*x);
    x += dx;
  }
  
  pi *= dx;
  
  printf("PI = %42.40f from %d Riemann sum iterations\n",pi,n);
  return 0;
}
