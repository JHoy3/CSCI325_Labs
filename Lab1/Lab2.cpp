#include <iostream>
#include <vector>


int main() {
    std::vector<double> temporatures = {72.5, 68.0, 74.0, 69.5};
    
    for (int i = 0; i < temporatures.size(); i++) {
        std::cout << i + 1 << ": " << temporatures[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}