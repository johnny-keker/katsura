#include <iostream>
#include <stdlib.h>

int calc_diff(int w[], int num) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < num; i++) {
        if (i < num / 2)
            sum1 += w[i];
        else
            sum2 += w[i];
    }
    return abs(sum1 - sum2);
}

int t_1005() {
    int num_rocks, sum1 = 0, sum2 = 0, res = 0, count = 0, min_diff = 200001;
    std::cin >> num_rocks;
    int weights[num_rocks];
    for (int i = 0; i < num_rocks; i++) {
        std::cin >> weights[i];
    }
    
    std::cout << min_diff << std::endl;
}