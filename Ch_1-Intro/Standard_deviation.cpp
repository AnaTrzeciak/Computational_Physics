//The Standard Algorithm fot the Standard Deviation
//Sigma is small compared to the average value <x>

//Let assume x(i) = i + 10^5 and N = 127

#include <iostream>
#include <math.h>
using namespace std;

int main(){

 int i;
 float sum, sumsq2, xbar, sigma1, sigma2;

 float x[127];  //array declaration with fixed dimension

 //initialise the data set

 for(i=0; i < 127; i++){
	x[i] = i + 100000.;
 }

 //the variable sum is the summer over all elements
 //the variable sumsq2 is the sum over x^2

 sum = 0.;
 sumsq2 = 0.;

 for(i = 0; i < 127; i++){
	sum += x[i];
 	sumsq2 += pow((double) x[i],2.);
 }
 //calculate the average and sigma

 xbar = sum/127;
 sigma1 = sqrt((sumsq2 - sum*xbar)/126.);

 /*Here comes the second algorithm where we calculate separately first the average and thereafter the sum which defines the standard deviation. The average has already been evaluated through xbar */

 sumsq2 = 0.;

 for(i = 0; i < 127; i++){
	sumsq2 += pow((double) (x[i] - xbar), 2.);
 }

 sigma2 = sqrt(sumsq2/126.);

 cout << "xbar = " << xbar << " " << "sigma1 = " << sigma1 << " " << "sigma2 = " << sigma2 << endl;

 return 0;


}
