#include <iostream>

int main() {
    int n, cur_num, sum, max_sum = 0;
    bool first_stage = true;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> cur_num;

        if (cur_num <= 0 && first_stage)
            continue;

        else if (cur_num > 0 && first_stage) {
            sum = cur_num;
            if (sum > max_sum)
                max_sum = sum;
            first_stage = false;
        }

        else if (cur_num >= 0) {
            sum += cur_num;
            if (sum > max_sum)
                max_sum = sum;
        }

        else if (sum - abs(cur_num) >= 0) {
            if (sum > max_sum)
                max_sum = sum;
            sum += cur_num;
        }

        else if (sum - abs(cur_num) < 0) {
            if (sum > max_sum)
                max_sum = sum;
            first_stage = true;
        }
    }
    std::cout << max_sum << std::endl;
    return 0;
}