/* A simple function which implements the trapezoidal rule

example: int (cos x)/(1 + x), 0.0 to 1.0
*/

#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){

 double trapez_sum;
 double fa, fb, x, step;
 int j, n;

 cout << "What is intervalo number n?" << endl;
 cin >> n;

//defining values
 double a = 0.0;
 double b = 1.0;

//calculating trapezoidal
 step = (b - a)/((double) n);
 fa = (cos(a)/(1 + a))/(2);
 fb = (cos(b)/(1 + b))/(2);

 trapez_sum = 0;

 for (j = 1; j <= n-1; j++){
	x = j*step + a;
	trapez_sum += cos(x)/(1 + x);
	cout << trapez_sum << endl;
 }

 trapez_sum = (trapez_sum + fb + fa)*step;

 
 cout << step << " " << fa << " " << fb << endl;
 cout << setprecision(6) << "I = " << trapez_sum << endl;
 cout << setprecision(6) << "Difference between real value and calculated value = 0.6010 - " << trapez_sum << " = " << 0.6010 - trapez_sum << endl; 

}
