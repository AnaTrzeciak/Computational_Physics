/*Interpolation using GSL library:

- cspline: Cubic spline with natural boundary conditions. piecewise cubic on each interval 
- Steffen’s method guarantees the monotonicity of the interpolating function between the given data points (for hard database).

compile:
$ g++ -Wall -I/usr/local/include -c interpol_gnu.cpp
$ g++ -L/usr/local/lib interpol_gnu.o -lgsl -lgslcblas -lm
$ ./a.out

*/

#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdlib.h> 
#include <sstream>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_spline.h>

using namespace std;

int main(void){

ifstream in;
in.open("data2.txt");

int N = 25; 
double x[N], y[N], xi, yi;

 for(int i = 0; i<=N; i++){
  in >> x[i] >> y[i]; 
  //cout << x[i] << ' ' << y[i] << endl;
 }

gsl_interp_accel *acc = gsl_interp_accel_alloc();
//gsl_spline *spline = gsl_spline_alloc (gsl_interp_cspline, N);
gsl_spline *spline_steffen = gsl_spline_alloc(gsl_interp_steffen, N);  
 
/*initializes the interpolation object*/ 
//gsl_spline_init(spline, x, y, N);
gsl_spline_init(spline_steffen, x, y, N);

for (int i = 0; i <= 100; i++){
   xi = (1 - i/100.0)*x[0] + (i/100.0)*x[N-1];
      
   //yi = gsl_spline_eval (spline, xi, acc);
   yi = gsl_spline_eval(spline_steffen, xi, acc);
   cout <<  xi << ' ' <<  yi << endl;
 }
 
 gsl_spline_free (spline_steffen);
 gsl_interp_accel_free (acc);

in.close();
return 0;
}
