#include <iostream>
#include <stdexcept>
#include <iomanip>

int main() {
    double result = 0.0;
    double num1, num2;
    char operation;
    
    std::cout << "=== Simple C++ Calculator ===" << std::endl;
    std::cout << "Operations: + - * / or 'c' to clear, 'q' to quit\n" << std::endl;
    
    while (true) {
        std::cout << "> ";
        std::cin >> num1 >> operation >> num2;
        
        if (operation == 'c') {
            result = 0.0;
            std::cout << "Cleared. Result: 0\n" << std::endl;
            continue;
        }
        
        if (operation == 'q') {
            std::cout << "Exiting calculator...\n";
            break;
        }
        
        if (operation == '+') {
            result = num1 + num2;
        } else if (operation == '-') {
            result = num1 - num2;
        } else if (operation == '*') {
            result = num1 * num2;
        } else if (operation == '/') {
            if (num2 == 0) {
                std::cerr << "Error: Division by zero\n";
                continue;
            }
            result = num1 / num2;
        }
        
        std::cout << "Result: " << result << std::endl << std::endl;
    }
    
    return 0;
}
