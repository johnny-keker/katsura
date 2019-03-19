#include <iostream>
#include <stdlib.h>

int main() {
    int num_rocks, sum1 = 0, sum2 = 0, weight;
    std::cin >> num_rocks;
    for (int i = 0; i < num_rocks; i++)
        std::cin >> weight;
        if (sum1 <= sum2 || sum2 >= ((sum1 + sum2) / 2))
            sum1 += weight;
        else
            sum2 += weight;
    std::cout << abs(sum1 - sum2) << std::endl;
    return 0;
}