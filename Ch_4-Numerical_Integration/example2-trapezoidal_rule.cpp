/* A simple function which implements the trapezoidal rule

example: int (2x + 3), 0.0 to 1.0
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
 fa = (2*a + 3)/(2);
 fb = (2*b + 3)/(2);

 trapez_sum = 0;

 for (j = 1; j <= n-1; j++){
	x = j*step + a;
	trapez_sum += (2*x + 3);
 }

 trapez_sum = (trapez_sum + fb + fa)*step;

 cout << step << endl;
 cout << setprecision(6) << "I = " << trapez_sum << endl;

}
