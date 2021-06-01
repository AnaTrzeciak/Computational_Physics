/*Exercise 3.1: Computing derivatives numerically*/
/*First derivative of f(x) = arctg(x) for x = srqt(2), using two formula for the derivative.

(i) f'(x) = (f(x+h) - f(x))/h 

(ii) f'(x) = (f(x+h) - f(x-h))/2h
*/

#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
	
 ofstream outfile;
 outfile.open("out_first_derivative_atang.txt");
   
 //declaration of variables
 double x = sqrt(2);
 int number_of_steps;
 double initial_step;
 double *h_step, *computed_derivative, *computed_derivative_sec;


  cout << "Read in from screen initial step and number of steps" << endl;
 cin >> initial_step;
 cin >> number_of_steps;

 h_step = new double[number_of_steps];
 computed_derivative = new double[number_of_steps];
 computed_derivative_sec = new double[number_of_steps];

 int counter;
 double h;

 h = initial_step;

//computing derivative

 for(counter = 0; counter < number_of_steps; counter++){
	
	h_step[counter] = h;
	computed_derivative[counter] = (atan(x + h) - atan(x))/h;  //first way calcule derivative

	computed_derivative_sec[counter] = (atan(x + h) - atan(x - h))/2*h;  //second way calcule derivative

	outfile << setprecision(8) << x << " " << h_step[counter] << " " << computed_derivative[counter] << " " << computed_derivative_sec[counter] << endl;

	h = h*0.5;
}
	
delete [] h_step;
delete [] computed_derivative;

outfile.close();

 return 0;
}
