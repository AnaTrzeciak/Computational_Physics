/*Exercise 2.2: Summing series*/

#include<iostream>
#include<math.h>

using namespace std;

int main(){

int number;
double term;
double sup = 0;
double sdown = 0; 

cout << "Enter with a number:";
cin >> number;

//somando de n=1 ate number;
for(double i=1; i<=number; i++){
	term = ((double) 1/i);
        sup += term;
}

//somando de number ate n=1;
for(double i=number; i>=1; i--){
	term = ((double) 1/i);
        sdown += term;
}


cout << "The sum of the above series is: sup = " << sup << " " << "sdown = " << sdown << endl;
}
