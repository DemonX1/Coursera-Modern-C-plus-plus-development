#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, i = 0;

    std::cin >> n;
    std::vector < int > vec(n);

    for (auto &item: vec) {
        item = n - i++;
    }

    do {
        for (const auto &item: vec) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    } while (std::prev_permutation(vec.begin(), vec.end()));

    return 0;
}
