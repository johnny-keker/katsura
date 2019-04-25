#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long compute_distance(vector<long long> const &xs, vector<long long> const &ys) {
  long long res = 0;
  for (int j = 0; j < (xs.size() - 1); ++j) {
    res += ((xs[j+1] - xs[j]) + (ys[j+1] - ys[j])) * (j + 1) * (xs.size() - j - 1) * 2;
  }
  return res;
}

int main() {
  long long n, x, y;
  cin >> n;
  vector <long long> x_s;
  vector <long long> y_s;
  for (long long i = 0; i < n; i++) {
    cin >> x >> y;
    x_s.push_back(x);
    y_s.push_back(y);
  }
  sort(x_s.begin(), x_s.end());
  sort(y_s.begin(), y_s.end()); 
  long long r = compute_distance(x_s, y_s) / (n * (n - 1));
  cout << r << endl;
  return 0;
}
