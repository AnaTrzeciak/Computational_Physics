/* A simple function which implements the trapezoidal rule

example: int dx/x, 3.0 to 3.6
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
 double a = 3.0;
 double b = 3.6;
 

//calculating trapezoidal

 step = (b - a)/((double) n);
 fa = (1/a)/(2);
 fb = (1/b)/(2);

 trapez_sum = 0;

 for (j = 1; j <= n - 1; j++){
	x = j*step + a;
	trapez_sum += 1/x;
 }

 trapez_sum = (trapez_sum + fb + fa)*step;

 cout << step << endl;
 cout << setprecision(6) << "I = " << trapez_sum << endl;
}
