#include<iostream>
#include<algorithm>



void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
    arr[i] = i + 1;
    }
}

//direct access
int directAccess(int arr[], int size, int index) {
    int inc = 0;
    if (index >= 0 && index < size) {
        std::cout << "Element at index " << index << " is: " << arr[index] << std::endl;
        inc += 1;
    } else {
        std::cout << "Element not found!" << std::endl;
        inc += 1;
    }
    return inc;
}


//oneLoop()
int oneLoop(int arr[], int size) {
    int inc = 0;
    for (int i = 0; i < size; i++){
        int currentElement = arr[i];
        inc ++;
        // std::cout << inc << ": " << currentElement << " "; 
    }
    return inc;
}

//divide by 2
int divideBy2(int size) {
    int inc = 0;
    while (size > 1 ) {
        size = size / 2;
        ++inc; 
    }
    return inc;
}

//inside loop d2
int insideLoopD2(int arr[], int size){
    int inc = 0;

    for (int i = 0; i < size; i++) {
        int temp = arr[i];
    
        while (temp > 0) {
            temp /= 2;
            inc++;
        }  
    }

    return inc;
}

//nested loop
int nestedLoop(int size) {
    int inc = 0;

    for (int i = 0; i < size; i++) {
        for(int g = 0; g < size; g++){
            inc ++;
        }
    }
    return inc;
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

    //asking for an index to access the element in each array, and the amout of actions taken to find the value.
    std::cout << "For direct access, please enter an index to access the element (Must be less than 10): ";
    int index = 0;
    std::cin >> index;
    int inc = directAccess(ten, 10, index);
    std::cout << "This took " << inc << " times to find the value at " << index << "." << std::endl;
    index = 0;

    std::cout << "For direct access, please enter an index to access the element (Must be less than 100): ";
    std::cin >> index;
    inc = directAccess(hundred, 100, index);
    std::cout << "This took " << inc << " times to find the value at " << index << "." << std::endl;
    index = 0;
    
    // std::cout << "For direct access, please enter an index to access the element (Must be less than 500): ";
    // std::cin >> index;
    // inc = directAccess(five_hundred, 500, index);
    // std::cout << "This took " << inc << " times to find the value at " << index << "." << std::endl;
    // index = 0;
    
    // std::cout << "For direct access, please enter an index to access the element (Must be less than 2000): ";
    // std::cin >> index;
    // inc = directAccess(two_thousand, 2000, index);
    // std::cout << "This took " << inc << " times to find the value at " << index << "." << std::endl;
    // index = 0;

    printf("\n");

    //calling oneLoop
    std::cout << "For a one loop with 10 elements:" << std::endl;
    inc = oneLoop(ten,10);
    std::cout << "This took " << inc << " iterations." << std::endl;

    // std::cout << "For a one loop with 100 elements:" << std::endl;
    // inc = oneLoop(hundred,100);
    // std::cout << "This took " << inc << " iterations." << std::endl;

    // std::cout << "For a one loop with 500 elemets:" << std::endl;
    // inc = oneLoop(five_hundred,500);
    // std::cout << "This took " << inc << " iterations." << std::endl;
    
    // std::cout << "For a one loop for 2000 elements:" << std::endl;
    // inc = oneLoop(two_thousand,2000);
    // std::cout << "This took " << inc << " iterations." << std::endl;

    printf("\n"); 

    //calling divide by 2
    std::cout << "For a divide by 2 with 10 elements:" << std::endl;
    inc = divideBy2(10);
    std::cout << "Took: " << inc << " iterations." << std::endl;

    // std::cout << "For a divide by 2 with 100 elements:" << std::endl;
    // inc = divideBy2(100);
    // std::cout << "Took: " << inc << " iterations." << std::endl;

    // std::cout << "For a divide by 2 with 500 elements:" << std::endl;
    // inc = divideBy2(500);
    // std::cout << "Took: " << inc << " iterations." << std::endl;

    // std::cout << "For a divide by 2 with 2000 elements:" << std::endl;
    // inc = divideBy2(2000);
    // std::cout << "Took: " << inc << " iterations." << std::endl;

    //inside loop
    std::cout << "inside loop: " << std::endl;
    inc = insideLoopD2(ten, 10);
    std::cout << "Inside loop took " << inc << " tries" << std::endl;
 
    //nested loop
    std::cout << "nested loop: " << std::endl;
    inc = nestedLoop(10);
    std::cout << "Inc = " << inc << std::endl;

    
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