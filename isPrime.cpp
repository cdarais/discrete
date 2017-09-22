#include <iostream>

bool checkPrime(int a){
	for (int i = 2; i <= a / 2; i++) if (a % i == 0) return false;
	return true;
}


int main(){

	int a;
	
	std::cout << "enter the number: ";
	std::cin >> a;

	std::cout << checkPrime(a) << std::endl;
}

