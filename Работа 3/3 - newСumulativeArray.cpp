#include <iostream>
#include <vector>

std::vector<int> formArrayB(const std::vector<int>& A) {
    int N = A.size();
    std::vector<int> B(N, 0);

    B[N - 1] = A[N - 1];
    
    for (int k = N - 2; k >= 0; --k) {
        B[k] = B[k + 1] + A[k];
    }

    return B;
}

int main() {
    std::vector<int> A = {4, 3, 2, 1, 6 , 7 ,9 , 10};
    std::vector<int> B = formArrayB(A);

    std::cout << "Массив B: ";
    for (int elem : B) {
        std::cout << elem << " ";
    }
    
    return 0;
}