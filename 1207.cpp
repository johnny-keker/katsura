#include <iostream>
#include <vector>
#include <tgmath.h>
#include <algorithm>

using namespace std;

const double PI = 3.141592653589793238462643383279502884197;

struct point {
  int x;
  int y;
  int n;
  double angle;
};

bool compare(const point& a, const point& b) {
  return a.y > b.y;
}

bool compare_angle(const point& a, const point& b) {
    if (a.angle != b.angle)
        return a.angle < b.angle;
    else
        return (sqrt(pow(a.x, 2) + pow(a.y, 2)) > sqrt(pow(b.x, 2) + pow(b.y, 2)));
}

vector<point> data;

double get_angle(int a, int b) {
  double x = (double)a;
  double y = (double)b;
  if (x > 0 && y > 0)
      return (atan(y / x) * (180.0 / PI));
  else if (x < 0 && y > 0)
      return (atan(-x / y) * (180 / PI)) + 90.0;
  else if (x < 0 && y < 0)
      return (atan(y / x) * (180 / PI)) + 180.0;
  else if (x > 0 && y < 0)
      return (atan(x / -y) * (180 / PI)) + 270.0;
  else if (x >= 0 && y == 0)
      return 0.0;
  else if (x == 0 && y > 0)
      return 90.0;
  else if (x < 0 && y == 0)
      return 180.0;
  return 270.0;
}

int main() {
  int n, res;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    data.push_back(point {x, y, i});
  }
  sort(data.begin(), data.end(), compare);
  res = data[n-1].n;
  /* moving to new axis */
  int new_x = data[n-1].x;
  int new_y = data[n-1].y;
  data.erase(data.end() - 1);
  for (int j = 0; j < n - 1; j++) {
    data[j].x -= new_x;
    data[j].y -= new_y;
    data[j].angle = get_angle(data[j].x, data[j].y);
  }
  /*--------------------*/
  sort(data.begin(), data.end(), compare_angle);
  cout << res << " " << data[(n - 1) / 2].n << endl;
}
