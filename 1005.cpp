#include <stdio.h>
#include <bitset>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n = 0, min_diff = 200001;
    uint32_t permutation = 0;
    cin >> n;
    int weights[n];
    for (int i = 0; i < n; i++)
        cin >> weights[i];
    if (n == 1) {
        cout << weights[0] << endl;
        return  0;
    }
    for (int j = 0; j < pow(2, n); j++) {
        bitset<20> pos = permutation;
        permutation++;
        int diff = 0;
        for (int k = 0; k < n; k++) {
            if (pos[k])
                diff += weights[k];
            else
                diff -= weights[k];
        }
        diff = abs(diff);
        if (diff == 0) {
            cout << 0 << endl;
            return  0;
        }

        if (diff < min_diff)
            min_diff = diff;
    }
    cout << min_diff << endl;
    return 0;
}