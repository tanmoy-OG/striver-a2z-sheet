#include <bits/stdc++.h>
using namespace std;

/*
  Time complexity: O(n)
  Space complexity: O(n)
*/
vector<string> brute(int n)
{
  vector<string> ans;
  generateAll("", n, ans);
  return ans;
}

void generateAll(string curr, int n, vector<string> &ans)
{
  if (curr.size() == n * 2)
  {
    if (isValid(curr))
      ans.push_back(curr);
    return;
  }
  generateAll(curr + '(', n, ans);
  generateAll(curr + ')', n, ans);
}

bool isValid(string curr)
{
  int cnt = 0;
  for (char it : curr)
  {
    it == '(' ? cnt++ : cnt--;
    if (cnt < 0)
      return false;
  }
  return cnt == 0;
}

/*------------------------------------*/

int main()
{
  int n;
  cin >> n;

  vector<string> b;
  b = brute(n);
  for (auto it : b)
    cout << it;
  cout << endl;

  return 0;
}