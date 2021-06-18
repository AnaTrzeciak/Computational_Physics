/* A simple function which implements the simpson's rule

example: int 4 (log(x) + x*x)dx/(x + 3)^{2}, 2 to 4
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
 double a = 2.0;
 double b = 4.0;

//calculating trapezoidal
 step = (b - a)/((double) n);
 fa = (log10(a) + a*a)/(pow(a + 3,2));
 fb = (log10(b) + b*b)/(pow(b + 3,2));

 simpson_sum = 0;

 for (j = 1; j <= n-1; j++){
	if( j%2 == 0){
	x = j*step + a;
	simpson_sum += 2*(log10(x) + x*x)/(pow(x + 3,2)); 
	}
	else{
	x = j*step + a;
	simpson_sum += 4*(log10(x) + x*x)/(pow(x + 3,2));	
	}
 }

 simpson_sum = (simpson_sum + fb + fa)*(step/3);

 
 cout << step << " " << fa << " " << fb << endl;
 cout << setprecision(6) << "I = " << simpson_sum << endl;

}
