/* A program example which uses  the Gauss-Legendre method to calculate integral.

int exp(x) cos(x)dx, 0.5 to 1.5 
*/

#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){

 double int_gauss = 0;
 double a = 0.5;
 double b = 1.5;
 
//mesh points and weights for 3 points

 double x[3] = {-0.77459667, 0, 0.77459667};
 double w[3] = {0.55555556, 0.88888889, 0.55555556};

 double w_til, x_til;

 for(int i = 0; i < 3; i++){
  
  w_til = ((b - a)*w[i])/2;
  x_til = ((b - a)*x[i])/2 + (b + a)/2;
 
  int_gauss += w_til*exp(x_til)*cos(x_til);
 }

 double expected = 1.27508;

 cout << "Expected Result = " << expected << endl;
 cout << "Gaussian Quadrature: I = " << int_gauss << endl;
 cout << "Global Error = " << expected - int_gauss << endl;

 return 0;
}
