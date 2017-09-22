#include <iostream>
#include <vector>

std::vector<bool> stuff;
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

int buckets(){
	int buckets;
	bool valid = false;
	while (!valid){
		std::cout << "2 or 3 buckets: ";
		std::cin >> buckets;
		if (buckets == 2 || buckets == 3) valid = true;
		else std::cout << "enter 2 or 3\n";
	}
	
	switch (buckets){
		case 2:
			while (!valid){
				std::cout << "relatively prime\n";
				std::cout << "small jug: ";
				std::cin >> sSize;

				std::cout << "big jug: ";
				std::cin >> lSize;

				if(lSize >= sSize){
					if (gcd(sSize, lSize) != 1) std::cout << "not relatively prime buckts\n\n";
					else valid = true;
				}else std::cout << "large needs to be bigger than small\n";
			}
			break;
		case 3:
			while (!valid){
				std::cout << "relatively prime\n";
				std::cout << "small jug: ";
				std::cin >> sSize;
	
				std::cout << "med jug: ";
				std::cin >> mSize;
			
				std::cout << "big jug: ";
				std::cin >> lSize;
	
				if (lSize >= mSize && lSize >= sSize){
					if(!(gcd(sSize, mSize) == 1 || gcd(sSize, lSize) == 1 || gcd(mSize, lSize) == 1)) std::cout << "not relatively prime\n\n\n";
					else valid = true;
				}else std::cout << "large > med > small\n";
			}
		break;
		default:
			std::cout << "invalid input";
			return -1;
	}
	for (int i = 0; i <= lSize; i++) stuff.push_back(false);
	return buckets;
}

int main(){
	
	bool valid = false;
	int s = 0, m = 0, l = 0, counter = 1;
	
	switch(buckets()){
		case 3:
			if (gcd(sSize, lSize) == 1){
				
				while (!allFound(l)){
					
					if (s == 0) fill(s, sSize);
					
					else if (l == lSize) empty(l);
					
					else move(s, l, lSize);
					
					std::cout << "step - " << counter << ": " << s << ", " << m << ", " <<  l << std::endl;
					counter++;
				}
			}
			else if (gcd(mSize, lSize) == 1){
		
				while (!allFound(l)){
					if (m == 0) fill(m, mSize);
					
					else if (l == lSize) empty(l);
					
					else move(m, l, lSize);
					
					std::cout << "step - " << counter << ": " << s << ", " << m << ", " <<  l << std::endl;
					counter++;
				}
			}
			else {
				while (!allFound(l)){

					if (m == 1) move(m, l, lSize);

					else if (s == 0) fill(s, sSize);

					else if (m == mSize) empty(m);
					
					else move(s, m, mSize);

					std::cout << "step - " << counter << ": " << s << ", " << m << ", " <<  l << std::endl;
					counter++;
				}
			}
			break;
		case 2:
			
			stepsRequired(sSize, lSize);
			
			while(!allFound(l)){
			
				if (s == 0) fill(s, sSize);
			
				else if (l == lSize) empty(l);
			
				else move (s, l, lSize);
			
				std::cout << "step - " << counter << ": " << s << ", " << l << std::endl;
				counter++;
			}
			break;
	}
	return 0;
}
