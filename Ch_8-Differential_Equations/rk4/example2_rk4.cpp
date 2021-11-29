/*The following program solves the second-order nonlinear Van der Pol oscillator equation:
 
  u''(t) + au'(t)[u(t)^{2} - 1 ] + u(t) = 0

 where a is a constant. This can be converted into a first order system introducing the variable v(t) = u'(t):
 
   u'(t) = v
   v'(t) = u(t) + av[u^{2} - 1]
 
 Initial condition:
   (u,v) = (1,0), and 0 < t < 100

 */

#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "rk4.cpp"

using namespace std;

void derivatives(double , double *, double *);

int main(){
 
 ofstream outfile;
 outfile.open("example2_rk4_out.txt");

 double *u, *du, *uout, *tout, *t, *u0;
 int m = 2;
 int number_of_steps = 2000;
 int a = 10;
  
//initial condition
 double t0 = 0.0;
 double tmax = 100.0; 

 t = new double[2];
 t[0] = t0;
 t[1] = tmax;

 u0 = new double[m];
 u0[0] = 1.0;   //u = 1
 u0[1] = 0.0;   //v = 0

 du = new double[m];
 u = new double[m];
 u[0] = u0[0];
 u[1] = u0[1];

 tout = new double[(number_of_steps + 1)*m];
 uout = new double[(number_of_steps + 1)*m];
 
 for(int i = 0; i <= number_of_steps; i++){
    
   rk4(derivatives, t, u0, number_of_steps, m, tout, uout);
  
   outfile << i << " " << tout[i] << " " << uout[i] << endl;
 }

 delete [] tout; delete [] uout;
 outfile.close();
return 0;
}

void derivatives(double t0, double *u, double *du){
 du[0] = u[1];
 du[1] = u[0] + 10*u[1]*(u[0]*u[0] - 1);
 } 
  
