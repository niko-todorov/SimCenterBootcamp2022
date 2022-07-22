// program to solve quadratic equation
//        ax^2 + bx + c = 0
//
// soln: x = -b/2a +/- sqrt(b^2-4ac)/2a
//
// write a program to take 3 inputs and output the soln
// deal with possible errors in input, i.e. b^2-4ac negative

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  if (argc != 4) {
    printf("Usage: appName a b c\n");
    exit(-1);
  }

  float a = atof(argv[1]);
  float b = atof(argv[2]);
  float c = atof(argv[3]);
  
  float x1, x2, _d = b*b-4*a*c;
  if (_d<0) {
    printf("The 2 roots are complex numbers\n");
    exit(-2);
  }
  x1 = (-b-sqrtf(_d))/(2*a);
  x2 = (-b+sqrtf(_d))/(2*a);

  printf("x1 = %f, x2 = %f\n", x1, x2);
  printf("Have a Nice Day!\n");
  return 0;
}

