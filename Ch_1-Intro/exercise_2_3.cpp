/*Exercise 2.3: Finding alternative expressions
Write a program which computes
 f(x) = x - sin(x) 
for a wide range of values of x. */

#include<iostream>
#include<math.h>

using namespace std;

int seno(float x, int n){
  
 float sum = 0;
 
 for(int i = 0; i <= n; i++){
    sum = pow(-1, n)*pow(x, 2*n+1);
    sum++;
 }
 return sum;
}


int fat(int n){
  int fatorial, i;
  fatorial = 1;
  
  for(i = n; i > 1; i--){
	fatorial = fatorial*i;
  }
  return fatorial;
}

int main(){

int x, n, fatorial;
double func, seno_teste;

cout << "Cálculo da função f(x) = x - sin(x). Digite o valor de x: "; 
cin >> x;

if(abs(x) >= 1.9){
	cout << "sen(x) = " << sin(x) << " rad" << endl;
        func = x - sin(x);
        cout << "O resultado é: " << func << endl;
}

if(abs(x) < 1.9){
 	cout << "O valor é menor que |1.9| e a serie de Taylor é usada para encontrar o resultado." << endl;
	cout << "Digite a quantidade de termos para a serie: ";
	cin >> n;
	fatorial  = fat(2*n+1);
        cout << "Fatorial: " << fatorial << endl;
	seno_teste = seno(x,n);
	cout << "Seno(x) = " << seno_teste << " rad" << endl;

	func = x - (seno_teste/fatorial);

	cout << "O resultado é: " << func << endl;
}
}
