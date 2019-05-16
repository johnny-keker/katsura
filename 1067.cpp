#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct dir {
  map<string, dir> children;
};

vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

void display_tree(const dir* e_p) {
  for (auto it = e_p->children.cbegin(); it != e_p->children.cend(); ++it) {
    cout << (*it).first << endl;
    display_tree(&it->second);
  }
}

int main() {
  dir entry_point;
  int r;
  string data;
  cin >> r;
  for (int j = 0; j < r; ++j) {
    cin >> data;
    dir* curr_dir = &entry_point;
    vector<string> dir_names = split(data, "\\");
    for (int i = 0; i < dir_names.size(); ++i) {
      string spaces(i, ' ');
      dir c;
      string name = spaces + dir_names[i];
      curr_dir->children.insert(pair<string, dir>(name, c));
      curr_dir = &curr_dir->children[name];
    }
  }
  display_tree(&entry_point);
  return 0;
}
