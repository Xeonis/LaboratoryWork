#include <iostream>
#include <vector>

// Функция для проверки симметричности квадратной матрицы относительно побочной диагонали
bool isSymmetric(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != matrix[n-j-1][n-i-1]) {
                return false;
            }
        }
    }
    
    return true;
}


 
void consoleOutput(bool condition) {
    if (condition) {
        std::cout << "Матрица симметрична относительно побочной диагонали." << std::endl;
    } else {
        std::cout << "Матрица не симметрична относительно побочной диагонали." << std::endl;
    }
}



int main() {

    std::vector<std::vector<int>> symetryMatrix = {
        {4, 3, 6, 10},
        {9, 5, 1, 6},
        {3, 7, 5, 3},
        {10, 3, 9, 4}
    };

    std::vector<std::vector<int>> asymetryMatrix = {
        {4, 3, 6, 10},
        {9, 5, 1, 6},
        {3, 7, 5, 3},
        {10, 1, 9, 4}
    };

    consoleOutput(isSymmetric(symetryMatrix));
    consoleOutput(isSymmetric(asymetryMatrix));

    return 0;
}