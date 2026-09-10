#include <iostream>
#include <vector>


int main() {
    std::vector<double> temporatures = {72.5, 68.0, 74.0, 69.5};
    
    //index based for loop
    for (int i = 0; i < temporatures.size(); i++) {
        std::cout << i + 1 << ": " << temporatures[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "Front of temps: " << temporatures.front();
    std::cout << std::endl;
    std::cout << "Back of temps: " << temporatures.back() << std::endl;
    std::cout << "Index 2 using []: " << temporatures[2] << std::endl;
    std::cout << "Index 2 using at: " << temporatures.at(2) << std::endl; 

    //range based for loop
    int inc = 1;
    for (double x : temporatures) {
        std::cout << inc << ": " << x << " ";
        inc += 1;
    }
    inc = 1;
    std::cout << std::endl;

    //range based for loop to add +1 to each temp
    for (double& x : temporatures) {
        x += 1;
    }

    std::cout << "After adding 1- ";
    for (double x : temporatures) {
        std::cout << inc << ": " << x << " ";
        inc += 1;
    }
    inc = 1;

    std::cout << std::endl;


    //numbers vector
    std::vector<int> numbers = {5,10,15,20,25};

    std::cout << "Using an index-based loop: ";
    for (int i; i < numbers.size(); i++) {
        std::cout << inc << ": " << numbers.at(i) << " "; 
        inc += 1;
    }
    std::cout << std::endl;
    inc = 1;

    std::cout << "Using a range-based loop: ";
    for (int x : numbers) {
        std::cout << inc << ": " << x << " ";
        inc += 1;
    }
    inc = 1;
    std::cout << std::endl;
    
    //using an iterator
    std::cout << "Loop using Iterators: ";
    for (auto it = numbers.begin(); it != numbers.end(); it++) {
        std::cout << inc << ": " << *it << " ";
        inc += 1; 
    }
    inc = 1;
    std::cout << std::endl;

    //scores
    std::vector<int> scores = {78,91,66,95,73,83,92,89,77};
    int first = 0;
    int second = 0;
    int third = 0;
    
    for (int score : scores) {
        if ( first > second) {
            third = second;
            second = first;
            first = score;
        }
        else if (score > second) {
            third = second;
            second = score;
        }
        else if (score > third) {
            third = score;
        }
    }
    std::cout << "1st: " << first << " " << "2nd: " << second << " " << "3rd: " << third << "\n";
    return 0;
}