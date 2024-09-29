#include <bits/stdc++.h>

using namespace std;

/*
  Brute Force Approach:
  Time complexity: O(3n)
  Space complexity: O(2n)
*/

string frequencySort(string s) {
  string ans = "";
  unordered_map<char, int> mp;
  multimap<int, char> mmp;
  for (auto it : s)
    mp[it]++;
  for (auto it : mp)
    mmp.insert(make_pair(it.second, it.first));
  for (auto it : mmp)
    ans = string(it.first, it.second) + ans;
  return ans;
}

int main() {
  string s;
  getline(cin, s);

  cout << frequencySort(s) << endl;

  return 0;
}