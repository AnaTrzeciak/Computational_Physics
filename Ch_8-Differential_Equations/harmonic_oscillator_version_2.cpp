/* This program solves Newton's equation for a block sliding on a horizontal frictionless surface. The block is tied to a wall with a spring, and Newton's equation takes the form

	m d^2x/dt^2 =-kx

with k the spring tension and m the mass of the block. The angular frequency is omega^2 = k/m and we set it equal 1 in this example program. Newton's equation is rewritten as two coupled differential equations, one for the position x and one for the velocity v 

	dx/dt = v and
	dv/dt = -x when we set k/m=1

*/

#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){

 ofstream outfile;
 outfile.open("out_harmonic_oscillator-rk4.txt");

 double pi = M_PI;

//declarations of variables
 double *xout, *vout;
 double initial_x, initial_v;
 int  number_of_steps;
 double t = 0.0;

 xout = new double[3000];
 vout = new double[3000];

   cout << "Initial position = ";
   cin >> initial_x;
   cout << "Initial speed = ";
   cin >> initial_v;
   cout << "Number of steps = ";
   cin >> number_of_steps;

 double h = 4.0*acos(-1)/((double) number_of_steps);
 double tmax = h*number_of_steps;
 xout[0] = initial_x;
 vout[0] = initial_v;

//runge-kutta parameters
 double k1, k2, k3, k4;             //for x
 double k1v, k2v, k3v, k4v;         //for v
	
 while (t <= tmax){ 
  for(int i = 0; i <= number_of_steps; i++){
   k1 = vout[i];
   k1v = -xout[i];

   k2 = vout[i] + k1*h*0.5;
   k2v = -(xout[i] + k1v*h*0.5);

   k3 = vout[i] + k2*h*0.5;
   k3v = -(xout[i] + k2v*h*0.5);
   
   k4 = vout[i] + k3*h;
   k4v = -(xout[i] + k3v*h);

   xout[i + 1] = xout[i] + h*(k1 + 2*k2 + 2*k3 + k4)/6;
   vout[i + 1] = vout[i] + h*(k1v + 2*k2v + 2*k3v + k4v)/6;

   outfile << xout[i] << " " << vout[i] <<  " " << t << endl;  
 
 t = t + h;  
  }
 
 }
 return 0;
}

