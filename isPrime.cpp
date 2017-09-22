#include <iostream>

bool checkPrime(int a){
	bool prime = true;
	for (int i = 2; i <= a / 2; i++) 
		if (a % i == 0){
			std::cout << "factor: " << i << std::endl; 
			prime = false;
		}
	return prime;
}


int main(){
	
	bool prime;
	int a;
	
	std::cout << "enter the number: ";
	std::cin >> a;
	
	prime = checkPrime(a);
	
	if(prime)
		std::cout << "is prime\n\n";
	else
		std::cout << "not prime\n\n";
}

