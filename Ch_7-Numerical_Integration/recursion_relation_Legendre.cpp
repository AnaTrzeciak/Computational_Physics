/*This function computes the Legendre polynomial of degree N using the recursion relation:

 (j + 1)L_{j+1}(x) + jL_{j-1}(x) - (2j + 1)xL_{j}(x) = 0

In this code: s = L_{j+1}
	      r = L_{j}
	      t = L_{j-1}	
*/

#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;

double legendre(int n, double x){

 double r, s, t;
 int m;

 r = 0 ; s = 1;

 for(m = 0; m < n; m++){
	t = r; r = s;
	s = (2*m + 1)*x*r - m*t;
	s /= (m + 1);
 }

 return s;
}

int main(){

 int n;
 double x;

 cout << "Polynomial order n = " << endl;
 cin >> n;
 cout << "Value of x = " << endl;
 cin >> x;

 cout << legendre(n, x) << endl;

}
