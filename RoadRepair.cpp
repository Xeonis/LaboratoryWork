//Можно было реализовать через деревья но я не смог поэтому тут тупой перебор который дает запредельную сложность на больших обьемах
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    // Создаем вектор для хранения уровней воды
    vector<int> water(r - l + 1, 0);

    // Вектор для хранения запросов на уровень воды
    vector<pair<char, int>> queries;


        for (int i = 0; i < n; i++) {
            char ci;
            int x;
            cin >> ci >> x;
            if (ci == '+') {
                int pos = ((r - l) - (r - x));
                water[pos]++;
                Found:
               for (int i = 0; i < r - l + 1; i++) {
                    if (water[i] >= 2) {
                        //стандартное перетекание 
                        if (i - 1 >= 0 && water[i - 1] < 2) water[i - 1]++;
                        if (i + 1 < r - l + 1 && water[i + 1] < 2) water[i + 1]++;
                        water[i] = 0;
                        if (i - 1 >= 0 && water[i - 1] == 2) {
                           i = i - 1;
                        }
                    }
                }
                for (int i = 0; i < r - l + 1; i++) {
                    if (water[i] >= 2) goto Found;
                }
                
        }else{
            queries.push_back(make_pair(ci, x - l));
        }
        
    }

    
    

    for (auto query : queries) {
        char ci = query.first;
        int x = query.second;

        if (ci == '?') {
         int pos = ((r - l) - (r - x));
            cout << water[pos] << endl;
        }
    }

    return 0;
}
