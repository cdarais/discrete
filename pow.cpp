#include <iostream>


int pow(int n, int &iteration){
	return n < 2 ? 1 : pow(n - 1, ++iteration) - pow(n - 2, ++iteration);
}


int main() {
	int num = 0, iteration = 0;
	
	std::cout << "enter -1 to quit\n";

	while (num != -1){
		
		std::cout << "enter amount: ";
		std::cin >> num;
		
		if (num == -1) return 0;
		
		pow(num, ++iteration);
		
		std::cout << "iterations: " << iteration << std::endl;
		iteration = 0;
	}
																		    return 0;
}
