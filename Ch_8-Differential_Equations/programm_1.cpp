/* This program solves Newton's equation for a block sliding on a horizontal frictionless surface. The block is tied to a wall with a spring, and Newton's equation takes the form

	m d^2x/dt^2 =-kx

with k the spring tension and m the mass of the block. The angular frequency is omega^2 = k/m and we set it equal 1 in this example program. Newton's equation is rewritten as two coupled differential equations, one for the position x and one for the velocity v 

	dx/dt = v and
	dv/dt = -x when we set k/m=1

We use therefore a two-dimensional array to represent x and v as functions of t

	y[0] == x
	y[1] == v
	dy[0]/dt = v
	dy[1]/dt = -x

The derivatives are calculated by the user defined function derivatives. The user has to specify the initial velocity (usually v_0=0) the number of steps and the initial position. In the programme below we fix the time interval [a,b] to [0,2*pi].
*/

#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
//#include "lib.h"
using namespace std;

//output file as global variable
ofstream ofile;

//function declarations
void derivatives(double, double *, double *);
void initialise ( double&, double&, int&);
void output( double, double *, double);
void runge_kutta_4(double *, double *, int, double, double, double *, void (*)(double, double *, double *));


int main(int argc, char* argv[]){

//declarations of variables
double *y, *dydt, *yout, t, h, tmax, E0;
double initial_x, initial_v;
int i, number_of_steps;
int n = 2;			//number of differential equations
char *outfilename;

//Read in output file, abort if there are too few command-line arguments
 if( argc <= 1 ){
  cout << "Bad Usage: " << argv[0] << "read also output file on same line" << endl;
  exit(1);
 }
 else{
  outfilename=argv[1];
}

 ofile.open(outfilename);

//allocate space in memory for the arrays containing the derivatives
 dydt = new double[n];
 y = new double[n];
 yout = new double[n];

//read in the initial position, velocity and number of steps
 initialise (initial_x, initial_v, number_of_steps);

//setting initial values, step size and max time tmax
 h = 4.*acos(-1.)/( (double) number_of_steps);  //the step size
 tmax = h*number_of_steps; 			//the final time
 y[0] = initial_x;
 y[1] = initial_v;
 t=0.;						//initial time
 E0 = 0.5*y[0]*y[0]+0.5*y[1]*y[1];              //the initial total energy

//now we start solving the differential equations using the RK4 method
	
  while (t <= tmax){
	derivatives(t, y, dydt); // initial derivatives
	runge_kutta_4(y, dydt, n, t, h, yout, derivatives);
	 for (i = 0; i < n; i++) {
	  y[i] = yout[i];
  	 }
	t += h;
 
   ofile << setprecision(5) << t << " " << y[0] << " " << y[1] << " " << cos(t) << " " << 0.5*pow(y[0],2) + 0.5*pow(y[1],2) - E0 << endl;
   //ofile << setprecision(8) << y[0];
   //ofile << setprecision(8) << y[1];
   //ofile << setprecision(8) << cos(t);
   //ofile << setprecision(8) << 0.5*pow(y[0],2) + 0.5*pow(y[1],2) << endl;
  }
 delete [] y; delete [] dydt; delete [] yout;
 ofile.close();     //close output file
return 0;
}

 void initialise (double& initial_x, double& initial_v, int& number_of_steps) {
   cout << "Initial position = ";
   cin >> initial_x;
   cout << "Initial speed = ";
   cin >> initial_v;
   cout << "Number of steps = ";
   cin >> number_of_steps;
 }

 void derivatives(double t, double *y, double *dydt){
   dydt[0]=y[1];   //derivative of x
   dydt[1]=-y[0];  //derivative of v
 }

 void runge_kutta_4(double *y, double *dydx, int n, double x, double h, double *yout, void (*derivs)(double, double *, double *)) {
  
  int i;
  double xh,hh,h6;
  double *dym, *dyt, *yt;

//allocate space for local vectors
  dym = new double [n];
  dyt = new double [n];
  yt = new double [n];
  hh = h*0.5;
  h6 = h/6.;
  xh = x+hh;

 for (i = 0; i < n; i++){
  yt[i] = y[i]+hh*dydx[i];
 }
 (*derivs)(xh,yt,dyt);    //computation of k2

 for (i = 0; i < n; i++){
  yt[i] = y[i]+hh*dyt[i];
 }
 (*derivs)(xh,yt,dym);   //computation of k3

 for (i=0; i < n; i++) {
  yt[i] = y[i]+h*dym[i];
  dym[i] += dyt[i];
 }
 (*derivs)(x+h,yt,dyt); //computation of k4

//now we upgrade y in the array yout
 for (i = 0; i < n; i++){
  yout[i] = y[i]+h6*(dydx[i]+dyt[i]+2.0*dym[i]);
 }

  delete []dym;
  delete [] dyt;
  delete [] yt;
}
