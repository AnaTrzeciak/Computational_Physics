/*Interpolation using GSL library:

- cspline_periodic: Cubic spline with natural boundary conditions. The last point in the data must have the same y-value as the first point.

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
in.open("data3_periodic.txt");

int N = 28; 
double x[N], y[N], xi, yi;
double junk_num;

 for(int i = 0; i<=N; i++){
  in >> y[i] >> x[i] >> junk_num; 
  cout << x[i] << ' ' << y[i] << endl;
 }

gsl_interp_accel *acc = gsl_interp_accel_alloc();
const gsl_interp_type *t = gsl_interp_cspline_periodic;
gsl_spline *spline = gsl_spline_alloc (t, N);
 
/*initializes the interpolation object*/ 
gsl_spline_init(spline, x, y, N);

for (int i = 0; i <= 100; i++){
   xi = (1 - i/100.0)*x[0] + (i/100.0)*x[N-1];
      
   //yi = gsl_spline_eval (spline, xi, acc);
   yi = gsl_spline_eval(spline, xi, acc);
   cout <<  xi << ' ' <<  yi << endl;
 }
 
 gsl_spline_free (spline);
 gsl_interp_accel_free (acc);

in.close();
return 0;
}
