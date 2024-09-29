#include <bits/stdc++.h>

using namespace std;

/*
  Brute Force Approach:
  Time complexity: O(n*n)
  Space complexity: O(1)
*/

string reverseWordsBrute(string s) {
  string ans;
  s.erase(0, s.find_first_not_of(" "));
  s.erase(s.find_last_not_of(" ") + 1);
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == ' ' && s[i + 1] != ' ' || i == 0) {
      string word;
      for (int j = i + 1; j < s.size() && s[j] != ' '; j++)
        word += s[j];
      if (i == 0)
        word = s[i] + word;
      else
        word += " ";
      ans += word;
    }
  }
  return ans;
}

/*
  Better Approach:
  Time complexity: O(2n)
  Space complexity: O(n)
*/

string reverseWordsBetter(string s) {
  string ans, word;
  stack<string> st;
  s.erase(0, s.find_first_not_of(" "));
  s.erase(s.find_last_not_of(" ") + 1);
  for (auto it : s) {
    if (it == ' ' && !word.empty()) {
      st.push(word);
      word = "";
    } else if (it != ' ')
      word += it;
  }
  st.push(word);
  for (int i = st.size() - 1; i >= 0; i--) {
    ans += st.top() + " ";
    st.pop();
  }
  ans.erase(ans.find_last_not_of(" ") + 1);
  return ans;
}

/*
  Optimized Approach:
  Time complexity: O(n)
  Space complexity: O(1)
*/

string reverseWordsOpti(string s) {
  string ans, word;
  s.erase(0, s.find_first_not_of(" "));
  s.erase(s.find_last_not_of(" ") + 1);
  s += " ";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') {
      if (s[i - 1] == ' ')
        continue;
      if (ans == "")
        ans = word;
      else
        ans = word + " " + ans;
      word = "";
    } else
      word += s[i];
  }
  return ans;
}

int main() {
  string s;
  getline(cin, s);

  cout << reverseWordsBrute(s) << endl;
  cout << reverseWordsBetter(s) << endl;
  cout << reverseWordsOpti(s) << endl;

  return 0;
}