#include <iostream>
#include <vector>
#include <string>

int show_vec(std::vector<int> vec) {
    int inc = 0;
    for (int i = 0; i < vec.size(); i++) {
        std::cout << inc << ": " << vec[i] << ", ";
        inc += 1;
    }
    std::cout << std::endl;
    return 0;
}

template <typename T>
T find_max(std::vector<T> values) {
    T maximum = values[0];
    for (int i = 1; i < values.size(); i++) {
        if (values[i] > maximum) {
            maximum = values[i];
        }
    }
    return maximum;
}

int main() {
    std::vector<int> scores = {};
    std::cout << "Total elements Before: " << scores.size() << std::endl;
    std::cout << "Capacity Before: " << scores.capacity() << std::endl;

    scores.push_back(78);
    scores.push_back(92);    
    scores.push_back(65);
    scores.push_back(88);
    scores.push_back(95);

    show_vec(scores);
    int inc = 0;

    std::cout << "total elements After: " << scores.size() << std::endl;
    std::cout << "capacity After: " << scores.capacity() << std::endl; //capacity goes from 0 to 8

    //scores maximum
    int maximum = scores[0];
    for (int i = 1; i < scores.size(); i++) {
        if (scores[i] > maximum) {
            maximum = scores[i];
        }
    }
    std::cout << "Maximum: " << maximum << std::endl;

    std::vector<int> numbers = {10,20,30,40,50};
    
    std::cout << "Numbers Vector: " << std::endl;
    show_vec(numbers);

    numbers.push_back(60);
    numbers.push_back(70);

    std::cout << "Numbers Vector: " << std::endl;
    show_vec(numbers);

    inc = 0;

    numbers.pop_back();

    std::cout << "Numbers Vector: " << std::endl;
    show_vec(numbers);
    
    inc = 0;

    std::cout << "Total elements: " << numbers.size() << std::endl;
    std::cout << "Total capacity: " << numbers.capacity() << std::endl;


    std::vector<int> a = {4,9,2,7};
    std::vector<double> b = {3.2,8.7,1.5,6.4};
    std::vector<std::string> c = {"Apple", "Orange", "Banana"};
    std::cout << "Maximum value in a: " << find_max(a) << std::endl;
    std::cout << "Maximum value in b: " << find_max(b) << std::endl;
    std::cout << "Maximum value in c: " << find_max(c) << std::endl;


    return 0;
}