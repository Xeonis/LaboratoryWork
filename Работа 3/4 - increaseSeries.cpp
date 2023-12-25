#include <iostream>
#include <vector>

void extendLongestSeries(std::vector<int> &array) {
    int N = array.size();
    if (N == 0) return;

    std::vector<int> seriesLengths(N, 1);
    int maxLength = 1;

    for (int i = 1; i < N; i++) {
        if (array[i] == array[i-1]) {
            seriesLengths[i] = seriesLengths[i-1] + 1;
            maxLength = std::max(maxLength, seriesLengths[i]);
        }
    }

    for (int i = 0; i < N; i++) {

        if ((seriesLengths[i] == maxLength &&
            (i == N-1 || array[i] != array[i+1]))) {
            array.insert(array.begin() + i + 1, array[i]);
            seriesLengths.insert(seriesLengths.begin() + i + 1, maxLength);
            i++;    
        }
    }
}

int main() {
    std::vector<int> array = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 6, 6};   
    
    extendLongestSeries(array);
    
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }

    return 0;
}