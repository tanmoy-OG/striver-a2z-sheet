#include <bits/stdc++.h>

using namespace std;

/*
  Brute Force Approach:
  Time complexity: O(n)
  Space complexity: O(n)
*/

int maxDepthBrute(string s) {
  stack<char> st;
  int maxi = 0;
  for (auto it : s) {
    if (it == '(')
      st.push(it);
    else if (it == ')')
      st.pop();
    maxi = max(maxi, (int)st.size());
  }
  return maxi;
}

/*
  Optimized Approach:
  Time complexity: O(n)
  Space complexity: O(1)
*/

int maxDepthOpti(string s) {
  int maxi = 0, cnt = 0;
  for (auto it : s) {
    if (it == '(') {
      cnt++;
      maxi = max(maxi, cnt);
    } else if (it == ')')
      cnt--;
  }
  return maxi;
}

int main() {
  string s;
  getline(cin, s);

  cout << maxDepthBrute(s) << endl;
  cout << maxDepthOpti(s) << endl;

  return 0;
}