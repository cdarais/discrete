#include <iostream>
#include <stack>

int main(){
	
	std::stack<int> left, middle, right, temp;
	int disks = 3, l, m, r, count = 0;
	std::cin >> disks;
	for (int i = disks; i > 0; i -= 1) left.push(disks);

	while ((left.size() != 0 || middle.size() != 0) && count < 30){

		if(middle.empty() && !left.empty()) {
			middle.push(left.top());
			left.pop();
		}
		else if(left.empty() && !middle.empty()){
			left.push(middle.top());
			middle.pop();
		}
		else if(left.top() < middle.top()){
			middle.push(left.top());
			left.pop();
		}
		else if(middle.top() < left.top()){
			left.push(middle.top());
			middle.pop();
		}
		else if(middle.empty() && !right.empty()){
			middle.push(right.top());
			right.pop();
		}
		else if(right.top() < middle.top()){
			middle.push(right.top());
			right.pop();
		}
		else if(left.top() < middle.top()){
			left.push(middle.top());
			left.pop();
		}
		count++;
	}
	std::cout << count << std::endl;

	return 0;
}
