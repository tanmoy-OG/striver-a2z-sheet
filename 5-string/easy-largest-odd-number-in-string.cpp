#include <bits/stdc++.h>

using namespace std;

/*
  Time complexity: O(n)
  Space complexity: O(1)
*/

string largestOddNumber(string num) {
  for (int i = num.size() - 1; i >= 0; i--) {
    if ((int)num[i] % 2 == 1) {
      string sb = num.substr(0, i + 1);
      return sb;
    }
  }
  return "";
}

int main() {
  string num;
  getline(cin, num);

  cout << largestOddNumber(num) << endl;

  return 0;
}