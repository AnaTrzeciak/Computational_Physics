/* Approximate the integral of f(x) from a to b by Simpson's rule.

    Simpson's rule approximates the integral \int_a^b f(x) dx by the sum:
    (dx/3) \sum_{k=1}^{N/2} (f(x_{2i-2} + 4f(x_{2i-1}) + f(x_{2i}))
    where x_i = a + i*dx and dx = (b - a)/N.

    Parameters
    ----------
    f : function
        Vectorized function of a single variable
    a , b : numbers
        Interval of integration [a,b]
    N : (even) integer
        Number of subintervals of [a,b]

    Returns
    -------
    float
        Approximation of the integral of f(x) from a to b using Simpson's rule with N subintervals of equal length.

example: int 4dx/(1 + x^{2}), 0.0 to 1.0. We must get the pi value.
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

 double expected = 3.1416; 

 cout << "Expected result = " << expected << endl;
 cout << setprecision(8) << "I = " << 4*simpson_sum << endl;

}
