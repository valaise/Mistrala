#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

void compute_prefix(string& p_t, vector<int>& s) {
  int border = 0;
  for (int i = 1; i < p_t.size(); i++) {
    while (border > 0 && p_t[i] != p_t[border]) {
      border = s[border - 1];
    }
    if (p_t[i] == p_t[border]) {
      border++;
      s[i] = border;
    }
    if (border == 0) {
      s[i] = 0;
    }
  }
}

vector<int> find_pattern(const string& pattern, const string& text) {
  vector<int> res;

  string p_t = pattern + '$' + text;
  vector<int> s( p_t.size() );
  compute_prefix( p_t, s );
  for (int i = pattern.size() + 1; i < p_t.size(); i++) {
    if (s[i] == pattern.size()) {
      res.push_back(i - 2 * pattern.size());
    }
  }
  return res;
}

int main() {

  string pattern, text;
  cin >> pattern;
  cin >> text;
  vector<int> ans = find_pattern( pattern , text );
  for (int i = 0; i < ans.size(); ++i) {
	cout << ans[i] << ' ';
  }

  return 0;

}