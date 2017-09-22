#include <iostream>
#include <vector>

std::vector<bool> stuff;
int maxNumbersToFind;
int sSize, mSize, lSize;

bool allFound(int &number){
	stuff[number] = true;
	for (int i = 1; i < stuff.size(); i++) if(stuff[i] == false) return false;
	return true;
}

void fill(int &a, int aSize){ a = aSize; }

void empty(int &a) { a = 0; }

void move(int &a, int &b, int bSize){
	int r = bSize - b;
	if (a + b > bSize){
		b = bSize;
		a -= r;
	}else {
		b += a;
		a = 0;
	}
}

void stepsRequired(int s, int b){ std::cout << "\n\nSteps required: " << 2 * (s + b - 2) << std::endl << std::endl; }

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b); }

int main(){
	
	bool valid = false;

	while (!valid){
		std::cout << "Relatively Prime\n";
		std::cout << "Small jug: ";
		std::cin >> sSize;

		std::cout << "Med jug: ";
		std::cin >> mSize;
		
		std::cout << "Big jug: ";
		std::cin >> lSize;

		std::cout << "Biggest number: ";
		std::cin >> maxNumbersToFind;

		if( lSize >= maxNumbersToFind) valid = true;
		
		if(!(gcd(sSize, mSize) == 1 || gcd(sSize, lSize) == 1 || gcd(mSize, lSize) == 1)) {
			std::cout << "not relatively prime\n\n\n";
			valid = false;
		}
	}
	
	for (int i = 0; i <= maxNumbersToFind; i++)	stuff.push_back(false);
	
	int s = 0, m = 0, l = 0, counter = 1;

	if (gcd(sSize, lSize) == 1){
		
		stepsRequired(sSize, lSize);

		while (!allFound(l)){
			if (s == 0) 
				fill(s, sSize);
			else if (l == lSize)
				empty(l);
			else
				move(s, l, lSize);
			std::cout << "step - " << counter << ": " << s << ", " << m << ", " <<  l << std::endl;
			counter++;
		}
	}else if (gcd(mSize, lSize) == 1){

		stepsRequired(mSize, lSize);

		while (!allFound(l)){
			if (m == 0) 
				fill(m, mSize);
			else if (l == lSize)
				empty(l);
			else
				move(m, l, lSize);
			std::cout << "step - " << counter << ": " << s << ", " << m << ", " <<  l << std::endl;
			counter++;
		}
	}else {
		while (!allFound(l)){
//			if (s == 1)
//				move(s, l, lSize);
			if (m == 1)
				move(m, l, lSize);
			else if (s == 0) 
				fill(s, sSize);
			else if (m == mSize)
				empty(m);
			else
				move(s, m, mSize);
			std::cout << "step - " << counter << ": " << s << ", " << m << ", " <<  l << std::endl;
			counter++;
		}
	}
	return 0;
}
