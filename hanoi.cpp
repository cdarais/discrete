#include <iostream>
#include <stack>
#include <cmath>

struct disk{
    int value;
    char last;
};

bool canMoveSide(std::stack<disk>& peg) { return peg.top().last != 'm'; }

bool canMoveMiddle(std::stack<disk>& peg) { return (peg.top().last != 'l' || peg.top().last != 'r'); }

void move(std::stack<disk>& start, std::stack<disk>& end, char location){
    start.top().last = location;
    end.push(start.top());
    start.pop();
}

bool startLessThanEnd(std::stack<disk> start, std::stack<disk> end){
    if (!end.empty()) return start.top().value < end.top().value;
    return true;
}

char moveMiddle(std::stack<disk>& left, std::stack<disk>& middle, std::stack<disk>& right){
    if (middle.top().last != 'l' && startLessThanEnd(middle, left)) {
        move(middle, left, 'm');
        return 'l';
    }
    
    else if (middle.top().last != 'r' && startLessThanEnd(middle, right)) {
        move(middle, right, 'm');
    }
    return 'r';
}

void generateDisks(std::stack<disk>& peg, int disks){
    disk temp;
    for (int i = disks; i > 0; i--) {
        temp.value = i;
        temp.last = 'u';
        peg.push(temp);
    }
}

bool isValue(std::stack<disk>peg, int value){
    if (!peg.empty()) return value == peg.top().value;
    return false;
}

void resetPegs(std::stack<disk>& peg1, std::stack<disk>& peg2){
    if (!peg1.empty()) peg1.top().last = 'u';
    if (!peg2.empty()) peg2.top().last = 'u';
}

int main() {
    std::stack<disk> left, middle, right;
    int count = 0;
    int disks;
    char movedMiddle = 'u';
    std::cout << "enter number of disks: ";
    std::cin >> disks;
    
    generateDisks(left, disks);
    
    while (!left.empty() || !middle.empty()) {
        for (int i = 1; i <= disks; i++) {
            if (isValue(left, i) && canMoveSide(left) && startLessThanEnd(left, middle)) {
                move(left, middle, 'l');
                resetPegs(left, right);
                i += disks;
            }else if (isValue(middle, i) && canMoveMiddle(middle)){
                movedMiddle = moveMiddle(left, middle, right);
                if (movedMiddle == 'r') resetPegs(left, middle);
                if (movedMiddle == 'l') resetPegs(middle, right);
                i += disks;
            }else if (isValue(right, i) && canMoveSide(right) && startLessThanEnd(right, middle)){
                move(right, middle, 'r');
                resetPegs(left, right);
                i += disks;
            }
        }
        count++;
    }
    std::cout << count << std::endl;
 	std::cout << std::pow(3,disks)-1 << std::endl;   

    
    return 0;
}
