#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

struct sign {
    int n;  // serial
    int c;  // count
};

vector<sign> data;

bool compare(const sign& a, const sign& b) {
    return a.c > b.c;
}

bool operator==(const sign a, const sign b) {
    return a.n == b.n;
}

int t_1604() {
    int k;
    cin >> k;
    int total = 0;
    for (int i = 1; i <= k; i++) {
        int c;
        cin >> c;
        total += c;
        data.push_back(sign{i, c});
    }
    sort(data.begin(), data.end(), compare);
    int prev = -1;
    while (total --> 0) {
        bool found = false;
        for (int j = 0; j < k; ++j) {
            if (data[j].c != 0 && data[j].n != prev) {
                cout << data[j].n << " ";
                data[j].c--;
                prev = data[j].n;
                if (j != k - 1 && data[j].c < data[j+1].c) {
                    sign tmp = data[j + 1];
                    data[j + 1] = data[j];
                    data[j] = tmp;
                }
                found = true;
                break;
            }
        }
        if (!found) {
            cout << data[0].n << " ";
            data[0].c--;
        }
    }
    return 0;
}
