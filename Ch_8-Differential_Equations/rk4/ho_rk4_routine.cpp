/*Programa que calcula EDO por runge-kutta de quarta ordem. 
O programa chama a função "rk4" do arquivo "rk4.cpp".

EDO:   dx/dt = v
       dv/dt = -x

We use therefore a two-dimensional array to represent x and v
as functions of t
	y[0] == x
	y[1] == v
	dy[0]/dt = v (y[1])
	dy[1]/dt = -x (y[0])

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
  outfile.open("ho_rk4_out.txt");

 double pi = M_PI;

 double *y, *dy, *yout, *tout, *t, *y0;
 int m = 2;
 int number_of_steps = 1000;

//initial condition
 double t0 = 0.0;
 double tmax = 4*pi; 

 t = new double[2];
 t[0] = t0;
 t[1] = tmax;

 y0 = new double[m];
 y0[0] = 0.0;
 y0[1] = 1.0;

 dy = new double[m];
 y = new double[m];
 y[0] = y0[0];
 y[1] = y0[1];

 tout = new double[(number_of_steps + 1)*m];
 yout = new double[(number_of_steps + 1)*m];
 
 for(int i = 0; i <= number_of_steps; i++){
    
   rk4(derivatives, t, y0, number_of_steps, m, tout, yout);
  
   outfile << i << " " << tout[i] << " " << yout[i] << endl;
 
 }

 delete [] tout; delete [] yout;
 outfile.close();
return 0;
}

void derivatives(double t0, double *y, double *dy){
 dy[0] = y[1];
 dy[1] = -y[0];
 } 
