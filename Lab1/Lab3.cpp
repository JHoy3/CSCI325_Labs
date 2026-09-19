#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    
    // Practice task
    vector<int> v = {5, 10, 15}; 
    
    // Loop A: begin() and end() allow modification. 
    for (auto it = v.begin(); it != v.end(); ++it) { 
        *it = *it + 1; 
    } 
    
    // Loop B: cbegin() and cend() provide read only access. 
    for (auto it = v.cbegin(); it != v.cend(); ++it) { 
        cout << *it << " "; 
        // *it = *it + 1;   // Uncomment to observe the error. | Throws a read only flag in the terminal
    } 
    cout << endl;


    // task 2
    const vector<int> scores = {78, 92, 65, 88, 74, 92};

    int target;
    cout << "Enter a score to find: ";
    cin >> target;


    auto it = find(scores.cbegin(),scores.cend(), target);

    if (it != scores.cend()){
        cout << "Found: " << *it << endl;
    } 
    // else {
    //     cout << target << " was not found." << endl;
    // }

    // Task 3
    vector<int> values = {78,92,65,88,74,92};
    cout << "Acending Order: " << endl;

    //ascending sort.
    sort(values.begin(),values.end());

    int inc = 1;
    for (auto it = values.cbegin(); it != values.cend(); ++it){
        cout << inc << ": " << *it << " ";
        inc += 1;
    }
    inc = 1;
    cout << endl;


    //decending sort.
    cout << "Decending Order: " << endl;
    sort(values.begin(),values.end(), greater<int>());

    for (auto it = values.cbegin(); it != values.cend(); ++it){
        cout << inc << ": " << *it << " ";
        inc += 1;
    }
    inc = 1;
    cout << endl;
    
    vector <int> Alg = {42,78,15,89,34,65,12,90,23,56};

    cout << "Algorithm Vector: " << endl;
    for (auto it = Alg.begin(); it != Alg.end(); ++it) {
        cout << inc << ": " << *it << " ";
        inc += 1;
    }
    inc = 1;
    cout << endl;

    // uses the max_element() and min_element() algorithms to find the maximum and minimum elements in the vector.
    cout << "Maximum element in Algorithm Vector using max_element(): " << *max_element(Alg.begin(),Alg.end()) << endl;
    cout << "Minimum element in Algorithm Vector using min_element(): " << *min_element(Alg.begin(),Alg.end()) << endl;

    return 0;
}