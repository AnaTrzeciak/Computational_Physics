/*Program to compute the second derivative of exp(x) for various values of x. 
Three calling functions are included in this version. In one functions we read in the data from screen, the next function computes the second derivative while the last function prints out data to screen.
*/

#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;

//defining the functions

void initialise(double *, double *, int *);				//reads from de screen the value of x, the initial step lenght h and the number of divisions by 2 of h
void second_derivative(int, double, double, double *, double *);	//calculate the second derivative of e^(x)	
void output(double *, double *, double, int);				//write in one file the result 


//int main(int argc, char* argv[]){
int main(){
//declarations of variables
 ofstream outfile;
 outfile.open("out_second_derivative_exp.txt");
 int number_of_steps;
 double x, initial_step;
 double *h_step, *computed_derivative;

//read in output file, abort if there are too few command-line arguments

/* if(argc <= 1){
	cout << "Bad Usage: " << argv [0] << " read also output file on same line" << endl;
	exit(1);
 }
 else{
	outfile = argv[1];
 }
*/

//read in input data from screen
 	cout << "Read in from screen initial step, x and number of steps" << endl;
	cin >> initial_step; 
 	cin >> x; 
	cin >> number_of_steps;

///allocate space in memory for the one-dimension arrays: h_step and computed_derivative
 h_step = new double[number_of_steps];
 computed_derivative = new double[number_of_steps];

  int counter;
  double h;
//calculate the step size
//initialise the derivative, y and x (in minutes) and iteration counter 

  h = initial_step;
//start computing for different step sizes

 for(counter = 0; counter < number_of_steps; counter++){

	h_step[counter] = h;
	computed_derivative[counter] = (exp(x+h) - 2*exp(x) + exp(x-h))/(h*h);
	
	outfile << setw(15) << setprecision(8) << x << " " << h_step[counter] << " " << computed_derivative[counter] << " " << exp(x) << endl;
  	
	h = h*0.5; 
 }


//free memory
 delete [] h_step;
 delete [] computed_derivative;

//close output file 
 outfile.close();

return 0;

}

/*void initialise(double *initial_step, double *x, int *number_of_steps){
	
	cout << "Read in from screen initial step, x and number of steps" << endl;
	cin >> *initial_step; 
 	cin >> *x; 
	cin >> *number_of_steps;
	return;
}
*/

/*void second_derivative(int number_of_steps, double x, double initial_step, double *h_step, double *computed_derivative){

  int counter;
  double h;
//calculate the step size
//initialise the derivative, y and x (in minutes) and iteration counter 

  h = initial_step;
//star computing for different step sizes

 for(counter = 0; counter < number_of_steps; counter++){

	h_step[counter] = h;
	computed_derivative[counter] = (exp(x+h) - 2*exp(x) + exp(x-h))/(h*h);

	h = h*0.5; 
 }
 
	return;
}*/

/*void output(double *h_step, double *computed_derivative, double x, int number_of_steps){

  int i; 
  ofile << "RESULTS: " << endl;
  ofile << setiosflags(ios::showpoint | ios::uppercase);
  for(i = 0; i < number_of_steps; i++){

	ofile << setw(15) << setprecision(8) << log10(h_step[i]);
	ofile << setw(15) << setprecision(8) << log10(fabs(computed_derivative[i] - exp(x))/exp(x)) << endl;

 }
}*/
