#include<iostream>
#include<algorithm>



void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
    arr[i] = i + 1;
    }
}

//direct access
void directAccess(int arr[], int size, int index) {
    if (index >= 0 && index < size) {
        std::cout << "Element at index " << index << " is: " << arr[index] << std::endl;
    } else {
        std::cout << "Element not found!" << std::endl;
    }
}


// test input size with 10, 100, 500, 2000
int main() {
    
    //creating dynamic arrays
    int* ten = new int[10];
    int* hundred = new int[100];
    int* five_hundred = new int[500];
    int* two_thousand = new int[2000];

    //filling the arrays
    fillArray(ten, 10);
    fillArray(hundred, 100);
    fillArray(five_hundred, 500);
    fillArray(two_thousand, 2000);

    //asking for an index to access the element in each array
    std::cout << "For direct access, please enter an index to access the element (Must be less than 10): ";
    int index = 0;
    std::cin >> index;
    directAccess(ten, 10, index);
    index = 0;

    std::cout << "For direct access, please enter an index to access the element (Must be less than 100): ";
    std::cin >> index;
    directAccess(hundred, 100, index);
    index = 0;
    
    std::cout << "For direct access, please enter an index to access the element (Must be less than 500): ";
    std::cin >> index;
    directAccess(five_hundred, 500, index);
    index = 0;
    
    std::cout << "For direct access, please enter an index to access the element (Must be less than 2000): ";
    std::cin >> index;
    directAccess(two_thousand, 2000, index);
    index = 0;




    //release and reset the pointers
    delete[] ten;
    ten = nullptr;
    delete[] hundred;
    hundred = nullptr;
    delete[] five_hundred;
    five_hundred = nullptr;
    delete[] two_thousand;
    two_thousand = nullptr;

}