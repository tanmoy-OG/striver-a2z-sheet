#include <bits/stdc++.h>

using namespace std;

/*
  Brute force approach:
  Time complexity: O(n)
  Space complexity: O(n)
*/

string removeOuterParenthesesBrute(string s) {
  string ans;
  stack<int> st;
  for (int i = 0; i < s.size(); i++) {
    if (st.size() == 1 && s[i] == ')') {
      st.pop();
      continue;
    } else if (!st.empty())
      ans += s[i];
    if (s[i] == '(')
      st.push(s[i]);
    else
      st.pop();
  }
  return ans;
}

/*
  Optimized approach:
  Time complexity: O(n)
  Space complexity: O(1)
*/

string removeOuterParenthesesOpti(string s) {
  string ans;
  int cnt1 = 0, cnt2 = 0;
  for (auto it : s) {
    if (it == '(')
      cnt1++;
    else
      cnt2++;
    if (cnt1 > 1 && cnt1 != cnt2)
      ans += it;
    else if (cnt1 == cnt2) {
      cnt1 = 0;
      cnt2 = 0;
    }
  }
  return ans;
}

int main() {
  string s;
  getline(cin, s);

  cout << removeOuterParenthesesBrute(s) << endl;

  return 0;
}