/* A simple function which implements the simpson's rule

example: int 4 (dx)/(1 + x^{2}), 0.0 to 1.0

obs: we must get the pi value.
*/

#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){

 double simpson_sum;
 double fa, fb, x, step;
 int j, n;

 cout << "What is intervalo number n?" << endl;
 cin >> n;

//defining values
 double a = 0.0;
 double b = 1.0;

//calculating trapezoidal
 step = (b - a)/((double) n);
 fa = (1/(1 + a*a));
 fb = (1/(1 + b*b));

 simpson_sum = 0;

 for (j = 1; j <= n-1; j++){
	if( j%2 == 0){
	x = j*step + a;
	simpson_sum += 2/(1 + x*x); 
	}
	else{
	x = j*step + a;
	simpson_sum += 4/(1 + x*x);	
	}
 }

 simpson_sum = (simpson_sum + fb + fa)*(step/3);

 
 cout << step << " " << fa << " " << fb << endl;
 cout << setprecision(6) << "I = " << 4*simpson_sum << endl;

}
