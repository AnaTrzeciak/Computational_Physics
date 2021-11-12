/*
Programa que utiliza Runge_Kutta de ordem 4 para calcular as soluções das equações não-lineares de Lotka-Volterra:

 dx/dt = ax - bxy
 dy/dt = -cy + dxy

onde a, b, c e d são constantes.
 */


#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

//open out file
 ofstream outfile;
 outfile.open("out_lotka_volterra-rk4.txt");

//defining constants
 const double a = 1.0;
 const double b = 1.0;
 const double c = 1.0;
 const double d = 2.0;
 double *yout, *xout; 

//initial conditions
 double x_0 = 1.0;
 double y_0 = 1.0;
 double t = 0.0;     //initial time

//runge-kutta parameters
 double h = 0.01;    //step size
 int number_of_steps = 2000; 
 double tmax = h*number_of_steps;
 double k1, k2, k3, k4;             //for x
 double k1y, k2y, k3y, k4y;         //for y
 yout = new double[3000];
 xout = new double[3000];

 yout[0] = y_0;
 xout[0] = x_0;
  
while (t <= tmax){ 
 for(int i = 0; i <= number_of_steps; i++){
   k1 = a*xout[i] - b*yout[i]*xout[i];
   k1y = -c*yout[i] + d*xout[i]*yout[i];

   k2 = a*(xout[i] + k1*h*0.5) - b*(yout[i] + h*k1y*0.5)*(xout[i] + k1*h*0.5);
   k2y = -c*(yout[i] + k1y*h*0.5) +d*(yout[i] + h*k1y*0.5)*(xout[i] + k1*h*0.5);

   k3 = a*(xout[i] + k2*h*0.5) - b*(yout[i] + h*k2y*0.5)*(xout[i] + k2*h*0.5);
   k3y = -c*(yout[i] + k2y*h*0.5) +d*(yout[i] + h*k2y*0.5)*(xout[i] + k2*h*0.5);
   
   k4 = a*(xout[i] + k3*h) - b*(yout[i] + h*k3y)*(xout[i] + k3*h);
   k4y = -c*(yout[i] + k3y*h) +d*(yout[i] + h*k3y)*(xout[i] + k3*h);

   xout[i + 1] = xout[i] + h*(k1 + 2*k2 + 2*k3 + k4)/6;
   yout[i + 1] = yout[i] + h*(k1y + 2*k2y + 2*k3y + k4y)/6;

   outfile << xout[i] << " " << yout[i] <<  " " << t << endl;  
 
 t = t + h*0.5;  
 }
 
}

return 0;
}
