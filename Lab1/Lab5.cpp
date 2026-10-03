#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

void printVector(std::vector<int> v, int counter) {
    for (auto it = v.begin(); it < v.end(); it++) {
        std::cout << counter << ": " << *it << " "; 
        ++counter;
    }
}

//function for binary search
int binarySearch(const std::vector<int>& v, int target, int& inc) {
    int low = 0;
    int high = static_cast<int>(v.size()) - 1;

    while (low <= high) {
        ++inc;

        int mid = low + (high - low) / 2;

        std::cout << inc << ": low: " << v[low] << " mid: " << v[mid] << " high: " << v[high] << std::endl;


        if (v[mid] == target) {
            return mid;
        }

        if (v[mid] < target) {
            low = mid + 1;
            std::cout << "Too low" << std::endl;
        } else {  
            high = mid - 1; 
            std::cout << "too high" << std::endl;
        }
    }
    return -1;
}

//insertion sort vector
 void InsertionSort(std::vector<int>& v) {
    for (int i = 1; i < v.size(); i++) {
        int key = v[i];
        int j = i - 1;

        if (i == 2) {
            std::cout << "After first iteration: " << std::endl;
            int counter = 0;
            printVector(v,counter);
            std::cout << std::endl;
        }

        if (i == 3) {
            std::cout << "After second iteration: " << std::endl;
            int counter = 0;
            printVector(v,counter);
            std::cout << std::endl;
        }

        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

void bubbleSort(std::vector<int>& v) {
    for (int i = 0; i < v.size() - 1; i++) {
        if (i == 2) {
            std::cout << "After first pass: ";
            int counter = 0; 
            printVector(v,counter);
            std::cout << std::endl;
        }

        if (i == 3) {
            std::cout << "After second pass: ";
            int counter = 0;
            printVector(v, counter);
            std::cout << std::endl; 
        }

        for (int j = 0; j < v.size() - i - 1; j++) {
            bool swapped = false;
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
                swapped = true;
            }
        }
    }
}

//merge function
void merge(std::vector<int>& v, const std::vector<int>& left, const std::vector<int>& right) {

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            v[k] = left[i];
            i++;
        } else {
            v[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left.size()) {
        v[k] = left[i];
        i++;
        k++;
    }

    while (j < right.size()) {
        v[k] = right[j];
        j++;
        k++;
    }
}


void mergeSort(std::vector<int>& v, int& divideCount, int& mergeCount) {
    const int inc = 0;
    if (v.size() <= 1) {
        return;
    }

    int mid = v.size() / 2;

    std::vector<int> left(v.begin(), v.begin() + mid);
    std::vector<int> right(v.begin() + mid, v.end());

    divideCount++;

    std::cout << "Divide " << divideCount << ":\n";

    std::cout << "Left: ";
    printVector(left, inc);
    std::cout << std::endl;
    
    std::cout << "Right: ";
    printVector(right, inc);
    std::cout << std::endl;

    mergeSort(left, divideCount, mergeCount);
    mergeSort(right, divideCount, mergeCount);

    merge(v, left, right);

    mergeCount++;

    std::cout << "Merge " << mergeCount << ":\n";
    printVector(v, inc);
    std::cout << std::endl;

}


int main () {

    //vector for binary search
    std::vector<int> data1 = {5,11,18,26,42,57,63};
    //sort array
    sort(data1.begin(), data1.end());

    //print vector
    int counter = 0;
    printVector(data1,counter);
    std::cout << std::endl;
    
    //promt to get target value
    std::cout << "Enter a value to search: ";
    int target = 0;
    std::cin >> target;

    //function call and print
    int inc = 0;
    int index = binarySearch(data1, target, inc);
    std::cout << "took: " << inc << std::endl;
    std::cout << "Found at index: " << index << std::endl;

    std::cout << "\n";

    //vector for sorts
    std::vector<int> values = {9,4,6,2,8};
    //copy vectors
    std::vector<int> InsertionVector = values;
    std::vector<int> BubbleVector = values;
    std::vector<int> MergeVector = values;

    //print vector that needs to be sorted
    std::cout << "Vector for sorts: " << std::endl;
    counter = 0;
    printVector(values,counter);
    std::cout << std::endl;
    

    std::cout << "Insertion sort: " << std::endl;


    //print vector before insertion sort
    counter = 0;
    std::cout << "Before Sort: " << std::endl;
    printVector(InsertionVector, counter);
    std::cout << std::endl;

    //call insertion sort function
    InsertionSort(InsertionVector);

    //print vector after insertion sort
    counter = 0;
    std::cout << "After Sort: " << std::endl;
    printVector(InsertionVector,counter);
    std::cout << std::endl << std::endl;


    std::cout << "Bubble Sort: " << std::endl;

    //print before sort
    std::cout << "Before Sort:";
    counter = 0;
    printVector(BubbleVector, counter);
    std::cout << std::endl;

    bubbleSort(BubbleVector);

    //print after sort
    std::cout << "After sort: ";
    counter = 0;
    printVector(BubbleVector, counter);
    std::cout << std::endl << std::endl;

    std::cout << "Merge Sort: " << std::endl;
    std::cout << "Before Sort:";
    counter = 0;
    printVector(MergeVector, counter);
    std::cout << std::endl;   

    int divcount = 0;
    int mergcount = 0;
    mergeSort(MergeVector,divcount,mergcount);

    std::cout << "After Sort: ";
    counter = 0;
    printVector(MergeVector, counter);
    std::cout << std::endl << std::endl;
    
    
    //Activity 2 vector
    std::vector<int> act2 = {14,5,9,2,11,7};
    
    std::cout << "Activity 2: " << std::endl;
    counter = 0;
    std::cout << "Before Bubble Sort: ";
    printVector(act2, counter);
    std::cout << std::endl;

    //sort vector
    bubbleSort(act2);

    counter = 0;
    std::cout << "After Sort:";
    printVector(act2, counter);
    std::cout << std::endl << std::endl;
    
    //promt to get target value
    target = 0;
    std::cout << "Enter a target value: ";
    std::cin >> target;
    
    //function call
    inc = 0;
    index = binarySearch(act2, target, inc);
    std::cout << "took: " << inc << std::endl;
    std::cout << "Found at index: " << index << std::endl;

    return 0;
}
