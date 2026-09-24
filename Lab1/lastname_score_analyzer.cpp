#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
// /workspaces/Lab1/Lab1/lastname_score_analyzer

// show elements of the container
void showscores(int scores[], int size){
    int inc = 1;
    for (int i = 0; i < size; i++) {
        std::cout << inc << ": " << scores[i] << " ";
        inc += 1; 
    }
    inc = 1; 
}

//finds minimum of the cotainer
int find_min(int scores[], int size) {
    int minimum = *std::min_element(scores, scores + size);
    return minimum;
}

//finds maximum of the cotainer
int find_max(int scores[], int size) {
    int maximum = *std::max_element(scores, scores + size);
    return maximum;
}

//finds average of the container
double find_average(int scores[], int size){
    double total = 0.00;
    //add all elements
    for (int i = 0; i < size; i++) {
        total += scores[i];
    }
    //find average
    double average = total / size;

    return average;
}

//find out how many scores are above the average
int above_average(int scores[], int size, double average) {
    int above_average = 0;
    for (int i = 0; i < size; i++) {
        if (scores[i] > average) {
            above_average += 1;
        }
    }

    return above_average;
}

//shows the elements of the vector
void show_vector(const std::vector<int>& scores_vector) {
    int inc = 1;
    for (auto it = scores_vector.begin(); it != scores_vector.end(); ++it) {
        std::cout << inc << ": " << *it << " ";
        inc += 1;
    }
    std::cout << std::endl;
} 

//find out the minimum of the vector
int find_min(const std::vector<int>& scores_vector) {
    int minimum = *std::min_element(scores_vector.begin(), scores_vector.end());
    return minimum;
}

//find out the maximum of the vector
int find_max(const std::vector<int>& scores_vector) {
    int maximum = *std::max_element(scores_vector.begin(), scores_vector.end());
    return maximum;
}



int main() {
    
    std::cout << "How many scores will be entered (nothing less than 1)? ";
    int size;
    std::cin >> size;

    // checking that size != -1
    while (size < 1) {
        std::cout << "You entered " << size << " which is not less than one. Try again: ";
        std::cin >> size;
    }

    std::cout << std::endl;

    // dynamic array of scores
    int* scores = new int [size];
    
    // asking each score
    for (int i = 0; i < size; i++) {
        std::cout << "Enter the scores: ";
        std::cin >> scores[i];
        while (scores[i] < 0 || scores[i] > 100) {
            std::cout << "Invalid score " << scores[i] << " is not between 1 and 100. Try again: ";
            std::cin >> scores[i];
        }
    }

    //function call to show scores
    showscores(scores, size);
    std::cout << std::endl;    
    
    //function call to find min
    int minimum = find_min(scores, size);
    std::cout << "Minimum: " << minimum; 
    std::cout << std::endl;

    //function call to find max
    int maximum = find_max(scores, size);
    std::cout << "Maximum: " << maximum;
    std::cout << std::endl;

    //function call to find average
    double average = find_average(scores, size);
    std::cout << "Average: " << std::fixed << std::setprecision(2) << average;
    std::cout << std::endl;

    //reset to default
    std::cout << std::fixed << std::setprecision(6);

    //function call to find number of elements above the average
    int over_average = above_average(scores, size, average);
    std::cout << "Number of elements above the average: " << over_average << std::endl;

    //Demonstrate pointer arithmetic by printing at least three elements with *(scores + i). Add a comment that explains why this matches scores[i]. !!!!!!!!!!!!!!!!!!!!!!!!!!
    std::cout << "Demonstrating pointer arithmetic: " << std::endl;
    std::cout << "First element: " << *(scores + 0) << " (matches scores[0])" << std::endl;
    std::cout << "Second element: " << *(scores + 1) << " (matches scores[1])" << std::endl;
    std::cout << "Third element: " << *(scores + 2) << " (matches scores[2])" << std::endl;


    //copying all elements form the array to the vector.
    std::vector<int> scores_vector(scores, scores + size);
    

    //release and reset the pointer
    delete[] scores;
    scores = nullptr;

    //function call to display all elements in the vector
    std::cout << "Scores in the vector: " << std::endl;
    show_vector(scores_vector);
    
    std::cout << "Please enter a value to search: ";
    int value = 0;
    std::cin >> value;

    // Search for the value in the vector
    auto it = std::find(scores_vector.begin(), scores_vector.end(), value);
    if (it != scores_vector.end()) {
        std::cout << "Value " << value << " found" << std::endl;
    } else {
        std::cout << "Value " << value << " not found" << std::endl;
    }

    //sorting and printing the elements in ascending order
    std::sort(scores_vector.begin(), scores_vector.end());
    std::cout << "Sorted scores, ascending: ";
    show_vector(scores_vector);


    // maximum values
    int vector_maximum = find_max(std::vector<int>(scores_vector.begin(), scores_vector.end()));
    std::cout << "Maximum: " << vector_maximum << std::endl;
    // minimum values
    int vector_minimum = find_min(std::vector<int>(scores_vector.begin(), scores_vector.end()));
    std::cout << "Minimum: " << vector_minimum << std::endl;

    //dispaly copacity and size of the vector
    std::cout << "Copacity of the vector: " << scores_vector.capacity() << std::endl;
    std::cout << "Size of the vector: " << scores_vector.size() << std::endl;

    return 0;

}

// Written understanding

// What is the difference between the pointer scores and the expression *scores?
// The pointer scores containes the address of the first element while *scores dereferences the pointer and gives the value at that address.

// Why must memory created with new[] be released with delete[] rather than delete?
// memory created with new[] must be released with delete[] because it is an array of values. If it was a normal dynamic value then delete would be just fine.

// What is a memory leak, and how does this program prevent one?
// A memory leak is when memory is allocated but not released properly. 
//This program prevents a memory leak by copying the values from the dynamic array to a vector and then releasing the memory allocated for the dynamic array using delete[] and reseting the pointer to nullptr.

// Why is vector generally safer than a manually allocated array?
// A vector is generally safer than a manually allocated array because it manages its own memory and provides bounds checking.

// What can happen to existing vector iterators when an insertion causes reallocation?
// When an insertion causes reallocation, existing vector iterators can become invalidated, meaning they may no longer point to the correct elements in the vector. 
// This can lead to undefined behavior if those iterators are used after reallocation.
