#include <iostream>
#include <vector>

// Функция для проверки симметричности массива
bool isArraySymmetric(const std::vector<char>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        if (arr[left] != arr[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

 
void consoleOutput(bool condition) {
    if (condition) {
        std::cout << "Массив строк симметричен." << std::endl;
    } else {
        std::cout << "Массив строк не симметричен" << std::endl;
    }
}


int main() {
    
    std::vector<char> symbolsSymetric = {'r', 'a', 'c', 'e', 'c', 'a', 'r'};
    std::vector<char> symbolsAsymetric = {'r', 'a', 'c', 'e', 'c', 'b', 'r'};
    
    consoleOutput(isArraySymmetric(symbolsSymetric));
    consoleOutput(isArraySymmetric(symbolsAsymetric));

    return 0;
}