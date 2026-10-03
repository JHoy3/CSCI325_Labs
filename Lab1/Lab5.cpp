#include<iostream>
#include<algorithm>
#include<vector>

//function for binary search
int binarySearch(const std::vector<int>& v, int target) {
    int inc = 0;
    int low = 0;
    int high = static_cast<int>(v.size()) - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid] == target) 
            return mid;
        if (v[mid] < target) 
            low = mid + 1;
        else  
            high = mid - 1;
        ++inc;
    }
    return inc;
}



int main () {

    std::vector<int> data1 = {5,11,18,26,42,57,63};
    sort(data1.begin(), data1.end());

    //print vector
    int counter = 0;
    for (auto it = data1.begin(); it < data1.end(); it++) {
        std::cout << counter << ": " << *it << " "; 
        ++counter;
    }
    std::cout << std::endl;
    
    std::cout << "Enter a value to search: ";
    int target = 0;
    std::cin >> target;

    binarySearch(data1, target);
    int inc = inc;
    std::cout << "took: " << inc;

    return 0;
}
