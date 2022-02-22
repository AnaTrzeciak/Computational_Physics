/* A simple function which implements the simpson's rule

example: int x^2
*/

#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;

//Defining function
#define f(x) exp(2*x)


int main(){

 double simpson_sum = 0.0;
 double fa, fb, x, step, a, b;
 int j, n;

 cout << "What is intervalo number n?" << endl;
 cin >> n;
 cout << "What is lower limit of intregation?" << endl;
 cin >> a;
 cout << "What is upper limit of intregation?" << endl;
 cin >> b;

//calculating integral
 step = (b - a)/((double) n);
 fa = f(a);
 fb = f(b);	

 simpson_sum = fa + fb;

 for (j = 1; j <= n-1; j++){

   x = j*step + a;	
     
   if( j%2 == 0){
    simpson_sum = simpson_sum + 2*(f(x));
   }
   else{
    simpson_sum = simpson_sum + 4*(f(x));	
   }
 }

  simpson_sum = (simpson_sum)*(step/3);

 cout << setprecision(6) << "I = " << simpson_sum << endl;

}
