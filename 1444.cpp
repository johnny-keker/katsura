#include <iostream>
#include <list>
#include <vector>
#include <tgmath.h>
#include <algorithm>

using namespace std;

const double PI = 3.141592653589793238462643383279502884197;

struct point {
    double angle;
    int num;
    long long int x;
    long long int y;
};

vector<point> field;

double get_angle(long long int a, long long int b) {
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

bool compare(const point& a, const point& b) {
  if (a.angle != b.angle)
    return a.angle < b.angle;
  else
    return (sqrt(pow(a.x, 2) + pow(a.y, 2)) < sqrt(pow(b.x, 2) + pow(b.y, 2)));
}

bool compare_backward(const point& a, const point& b) {
  if (a.angle != b.angle)
    return a.angle > b.angle;
  else
    return (sqrt(pow(a.x, 2) + pow(a.y, 2)) < sqrt(pow(b.x, 2) + pow(b.y, 2)));
}

int find_min(vector<point> field) {
  int res = 0;
  for (int y = 0; y < field.size(); y++) {
    if (field[y].y < field[res].y)
      res = y;
    else if (field[y].y == field[res].y)
      if (field[y].x < field[res].x)
        res = y;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  point first;
  int up = 0, down = 0;
  for (int i = 1; i <= n; i++) {
      long long int x, y;
      cin >> x >> y;
      point current = point { 0.0, i, x, y};
      field.push_back(current);
      if (i == 1)
          first = current;
      else {
        if (x == 0) {
          if (y > 0)
            up++;
          else if (y < 0)
            down++;
        }
      }
  }
  int bottom = find_min(field);
  int new_x = field[bottom].x;
  int new_y = field[bottom].y;
  field[bottom].x = 0;
  field[bottom].y = 0;
  field[bottom].angle = 100500.0;
  for (int j = 0; j < n; j++) {
    if (j == bottom)
      continue;
    field[j].x -= new_x;
    field[j].y -= new_y;
    field[j].angle = get_angle(field[j].x, field[j].y);
  }
  int c = 0;
  std::sort(field.begin(), field.end(), compare);
  for (int p = 0; p < n; p++) {
    if (field[p].num != first.num) 
      c++;
    else break;
  }
  std::rotate(field.begin(), field.begin() + c, field.end());
  cout << n << endl;
  if (down == 0 || up == 0) {
    for (int r = 0; r < n; r++) {
        point curr = field[r];
        cout << curr.num << endl;
    }
  }
  else {
    std::sort(field.begin(), field.end(), compare_backward);
    c = 0;
    for (int p = 0; p < n; p++) {
      if (field[p].num != first.num) 
        c++;
      else break;
    }
    std::rotate(field.begin(), field.begin() + c, field.end());
    cout << field[0].num << endl;
    for (int r = 1; r < n; r++)
      cout << field[r].num << endl;
  }
  return 0;
}
