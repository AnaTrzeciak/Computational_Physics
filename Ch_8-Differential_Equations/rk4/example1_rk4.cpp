/*Programa que calcula EDO por runge-kutta de quarta ordem. 
O programa chama a função "rk4" do arquivo "rk4.cpp".

EDO:   dy/dx = x - y + 2
 
  condição inicial: y(0) = 2
*/


#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "rk4.cpp"


using namespace std;

void derivatives(double , double *, double *);


int main(){

  double *x, *y0, *xout, *yout, *y, *dy;
  int number_of_steps = 10;
  int m = 1;   
 
  double x0 = 0.0;
  double xmax = 1.0;
 
  x = new double[2];
  x[0] = x0;
  x[1] = xmax; 

  y0 = new double[m];
  y0[0] = 2;

  xout = new double[(number_of_steps + 1)*m]; 
  yout = new double[(number_of_steps + 1)*m]; 

  dy = new double[m];
  y = new double[m];
  y[0] = 2.0; 
 
  
  for(int i = 0; i <= number_of_steps; i++){
   rk4(derivatives, x, y0, number_of_steps, m, xout, yout);
   cout << i << " " << xout[i] << " " << yout[i] << endl; 
  }
  
 delete [] xout; delete [] yout;
 return 0;
 }

 void derivatives(double x0, double *y, double *dy){
  dy[0] = x0 - y[0] + 2.0;
 }
