#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <sstream>

class Calculator {
private:
    double result = 0.0;

public:
    void add(double num) { result += num; }
    void subtract(double num) { result -= num; }
    void multiply(double num) { result *= num; }
    void divide(double num) { 
        if (num == 0) throw std::invalid_argument("Division by zero");
        result /= num;
    }
    void clear() { result = 0.0; }
    
    double getResult() const { return result; }
    std::string toString(double precision = 6) const {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(precision) << result;
        return oss.str();
    }
};

int main() {
    Calculator calc;
    double num1, num2;
    char operation;
    
    std::cout << "=== Simple C++ Calculator ===" << std::endl;
    std::cout << "Operations: + - * / or 'c' to clear, 'q' to quit\n" << std::endl;
    
    while (true) {
        std::cout << "> ";
        std::cin >> num1 >> operation >> num2;
        
        if (operation == 'c') {
            calc.clear();
            std::cout << "Cleared. Result: 0\n" << std::endl;
            continue;
        }
        
        if (operation == 'q') {
            std::cout << "Exiting calculator...\n";
            break;
        }
        
        double result = calc.getResult();
        
        switch (operation) {
            case '+': 
                calc.add(num1);
                break;
            case '-':
                calc.subtract(num2);
                break;
            case '*':
                calc.multiply(num2);
                break;
            case '/':
                try {
                    calc.divide(num2);
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                    continue;
                }
                break;
        }
        
        std::cout << "Result: " << result << std::endl << std::endl;
    }
    
    return 0;
}
