#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores = {};
    std::cout << "Total elements Before: " << scores.size() << std::endl;
    std::cout << "Capacity Before: " << scores.capacity() << std::endl;

    scores.push_back(78);
    scores.push_back(92);    
    scores.push_back(65);
    scores.push_back(88);
    scores.push_back(95);

    int inc = 0;
    for (int i = 0; i < scores.size(); i++) {
        std::cout << inc << ": " << scores[i] << ", ";
        inc += 1;
    }
    std::cout << std::endl;
    inc = 0;

    std::cout << "total elements After: " << scores.size() << std::endl;
    std::cout << "capacity After: " << scores.capacity() << std::endl; //capacity goes from 0 to 8

    //scores maximum
    int maximum = scores[0];
    for (int i = 0; i < scores.size(); i++) {
        if (scores[i] > maximum) {
            maximum = scores[i];
        }
    }
    std::cout << "Maximum: " << maximum << std::endl;

    std::vector<int> numbers = {10,20,30,40,50};

    for (int i = 0; i < numbers.size(); i++) {
        std::cout << inc << ": " << numbers[i] << ", ";
        inc += 1;
    }
    inc = 0;
    std::cout << std::endl;

    numbers.push_back(60);
    numbers.push_back(70);
 
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << inc << ": " << numbers[i] << ", ";
        inc += 1;
    }
    inc = 0;
    std::cout << std::endl;

    numbers.pop_back();

    for (int i = 0; i < numbers.size(); i++) {
        std::cout << inc << ": " << numbers[i] << ", ";
        inc += 1;
    }
    inc = 0;
    std::cout << std::endl;   

    std::cout << "Total elements: " << numbers.size() << std::endl;
    std::cout << "Total capacity: " << numbers.capacity() << std::endl;


    return 0;
}