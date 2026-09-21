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

int main() {
    
    std::cout << "How many scores will be entered (nothing less than 1)? ";
    int size;
    std::cin >> size;

    // checking that n != -1
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
        std::cout << std::endl;
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


    delete[] scores;
    scores = nullptr;


}