#include <iostream>
#include <math.h> 
#include <vector>

void unstable_binary_search(int target, std::vector<int> sorted_array) {
    int L = 0;
    int R = sorted_array.size();
    bool found = false;
    int midpoint;
    while (L<=R && found == false) {
        midpoint = int((L + R)/2);
        if (sorted_array[midpoint] == target) {
            found = true;
        }
        else {
            if (target < sorted_array[midpoint]) {
                R = midpoint - 1;
            }
            else {
                L = midpoint + 1;
            }
        }
    }
    if (found != false) {
        std::cout << midpoint << std::endl;
    }
    else {
        std::cout << "Not in list" << std::endl;
    }
}

void stable_binary_search(int target, std::vector<int> sorted_array) {
    int L = 0;
    int R = sorted_array.size();
    bool found = false;
    int midpoint;
    while (L<=R && found == false) {
        midpoint = L + int((R - L)/2);
        if (sorted_array[midpoint] == target) {
            found = true;
        }
        else {
            if (target < sorted_array[midpoint]) {
                R = midpoint - 1;
            }
            else {
                L = midpoint + 1;
            }
        }
    }
    if (found != false) {
        std::cout << midpoint << std::endl;
    }
    else {
        std::cout << "Not in list" << std::endl;
    }
}

int main() {
    int target = pow(2, 31) - 1;
    int size = pow(2, 31) - 2;
    std::vector<int> sorted_array; 
    int number = 1;
    for (int i = 0; i <= size; i++) {
        sorted_array.push_back(number);
        number+=1;
    }

    std::cout << "Stable result, position of target in array: " << std::endl;
    stable_binary_search(target, sorted_array); 
    std::cout << "Untable result, position of target in array: " << std::endl;
    unstable_binary_search(target, sorted_array);
}
