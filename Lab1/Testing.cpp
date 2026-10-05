#include<iostream>

int linearSearch(const vector<int>& v, int target) {  // O(n)
    for (int i = 0; i < v.size(); i++){
        if (v[i] == target) {
            return 1;
        }
        return -1;
    }

}


int BinarySearch(const vector<int>& v, int target) { // O(logn)
    int low = 0;
    int high = static_cast<int>(v.size()) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid] == target) {
            return mid;
        }
        if (v[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        return -1;
    }
}

void insertionSort(vector<int>& v) {     // O(n^2)
    for (int i = 1; i < v.size(); i++) {
        int key = v[i];
        int j = i -1;

        while (j >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

void selectionSort(vector<int>& v) {
    for (int i = 0; i < v.size()-1; i++) {
        int minIndex = i;

        for (int j = 1; j < v.size(); j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(v[i], v[minIndex]); // requires #include<utility>
        }
    }
}

void bubbleSort(vector<int>& v) {
    for (int end = v.size() -1; end > o; end--) {
        bool swapped = false;

        for (int i = 0; i < end; i++) {
            if (v[i] > v[i+1]) {
                swap(v[i], v[i + 1]);
                swapped = true;
            }
        }
        if (!swapped){
            break;
        }
    }
}

void merge(vector<int>& v, vector<int>& left, vector<int>& right) {
    int t = 0; // index for left
    int j = 0; // index for right
    int k = 0; // index for v

    //comparing left and right
    while (t < left.size() && j < right.size()) {
        if (left[t] < right[j]) {
            v[k] = left[t];
            t++;
        } else {
            v[k] = right[j];
            j++;
        }
        k++;
    }
    // copy anything remaining in left
    while (t < left.size()) {
        v[k] = left[t];
        t++;
        k++;
    }
    //copy anything from remaining in right
    while (t < right.size()){
        v[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& v) {
    if(v.size() <= 1)
    return;
}


int main () {

    // O(1) constant time
    // int value = numbers[index];   

    // O(logn) Logorithmic 
    while (left <= right) {
        int mid = left + (right - left) /2

        if (numbers[mid] == target) {
            cout << "Found" << endl;
            break;
        }
        else if (numbers[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
 
    // O(n) Linear time     / used for linear search
    for (int i = 0; i < n; i++) {
        cout << numbers[i];
    }

    // O(n log n) linearithmic 
    for (int i = 0; i < n; ++i) {
        int remaining = n;
        while (remaining > 1) {
            remaining /= 2;
        }
    }

    // O(n^2) Quadratic time
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            compare(numbers[i], numbers[j]);
        }
    }

    //O(2^n) Exponential time
    void choose(int level) {
        if (level == n) retrun;

        choose(level + 1);
        choose(level + 1);

    }


    return 0;
}