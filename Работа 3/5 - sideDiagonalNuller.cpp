#include <iostream>
#include <vector>

int main() {
    const int M = 4;
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };


    for (int i = 0; i < M; ++i) {
        for (int j = 0; j <= M - i - 1; ++j) {
            matrix[i][M - j - 1] = 0;
        }
    }

    for (const auto &row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}