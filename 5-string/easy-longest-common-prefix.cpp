#include <bits/stdc++.h>

using namespace std;

/*
  Bruteforce approach:
  Time complexity: O(n^2)
  Space complexity: O(1)
*/

string longestCommonPrefixBrute(vector<string> &strs) {
  string ans = "", prefix = "";
  for (int i = 0; i < strs[0].size(); i++) {
    prefix += strs[0][i];
    for (int j = 0; j < strs.size(); j++) {
      string sb = strs[j].substr(0, i + 1);
      if (sb != prefix)
        return ans;
    }
    ans = prefix;
  }
  return ans;
}

/*
  Optimized approach:
  Time complexity: O(nlogn)
  Space complexity: O(1)
*/

string longestCommonPrefixOpti(vector<string> &strs) {
  string ans = "";
  sort(strs.begin(), strs.end());
  int len = strs.size();
  string first = strs[0], last = strs[len - 1];
  for (int i = 0; i < min(first.size(), last.size()); i++) {
    if (first[i] != last[i])
      return ans;
    ans += first[i];
  }
  return ans;
}

int main() {
  vector<string> s;
  string temp;

  while(getline(cin, temp))
    s.push_back(temp);
    
  cout << longestCommonPrefixBrute(s) << endl;
  cout << longestCommonPrefixOpti(s) << endl;

  return 0;
}