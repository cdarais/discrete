#include <iostream>


int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b); }

int main(){
	int a, b, c;

	std::cout << "number 1: ";
	std::cin >> a;

	std::cout << "number 2: ";
	std::cin >> b;

	if (a > b) c = gcd(b,a);
	else c = gcd(a,b);

	std::cout << "gcd: " << c << std::endl;

	return 0;

}
