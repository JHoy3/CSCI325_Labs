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


void selectionSort(vector<int>& v) {            // O(n^2)
    for (int i = 0; i < v.size()-1; i++) {
        int minIndex=  i;

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


void bubbleSort(vector<int>& v) {               // O(n^2)
    for (int end = v.size() -1; end > 0; end--) {   // needs #include<utility>   this is needed for the swap functionalility
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


void mergeSort(vector<int>& v) {
    if(v.size() <= 1)
    return;

    int mid = v.size() / 2;

    vector<int> left(v.begin(), v.begin() + mid);
    vector<int> right(v.begin() + mid, v.end());

    megeSort(left);
    mergeSort(right);

   merge(v, left, right); 
}


void merge(vector<int>& v, vector<int>& left, vector<int>& right) {
    int l = 0; // index for left
    int j = 0; // index for right
    int k = 0; // index for v

    //comparing left and right
    while (l < left.size() && j < right.size()) {
        if (left[l] < right[j]) {
            v[k] = left[l];
            l++;
        } else {
            v[k] = right[j];
            j++;
        }
        k++;
    }
    // copy anything remaining in left
    while (l < left.size()) {
        v[k] = left[t];
        t++;
        k++;
    }
    //copy anything from remaining in right
    while (l < right.size()){
        v[k] = right[j];
        j++;
        k++;
    }
}
