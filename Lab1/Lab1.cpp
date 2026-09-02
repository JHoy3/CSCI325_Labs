#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores = {};
    scores.push_back(78);
    scores.push_back(92);    
    scores.push_back(65);
    scores.push_back(88);
    scores.push_back(95);

    int a = 0;
    for (int i = 0; i < scores.size(); i++) {
        std::cout << a << ": " << scores[i] << std::endl;
        a += 1;
    }

    std::cout << "This is the back, " << scores.back() << ". Total elements: " << scores.size() << std::endl;

    return 0;
}