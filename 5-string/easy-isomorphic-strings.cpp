#include <bits/stdc++.h>

using namespace std;

/*
  Bruteforce approach:
  Time complexity: O(n^2)
  Space complexity: O(1)
*/

bool isIsomorphicBrute(string s, string t) {
  for (int i = 0; i < s.size(); i++) {
    char ch1 = s[i];
    char ch2 = t[i];
    for (int j = i; j < s.size(); j++)
      if (s[j] == ch1 && t[j] != ch2 || t[j] == ch2 && s[j] != ch1)
        return false;
  }
  return true;
}

/*
  Optimized approach:
  Time complexity: O(n)
  Space complexity: O(2n) (2 unordered maps)
*/

bool isIsomorphicOpti(string s, string t) {
  unordered_map<char, char> mp1;
  unordered_map<char, char> mp2;
  for (int i = 0; i < s.size(); i++) {
    if (mp1.find(s[i]) == mp1.end() && mp2.find(t[i]) == mp2.end()) {
      mp1[s[i]] = t[i];
      mp2[t[i]] = s[i];
    } else {
      if (mp1[s[i]] != t[i] || mp2[t[i]] != s[i])
        return false;
    }
  }
  return true;
}

int main() {
  string s, t;
  getline(cin, s);
  getline(cin, t);

  cout << isIsomorphicBrute(s, t) << endl;
  cout << isIsomorphicOpti(s, t) << endl;

  return 0;
}