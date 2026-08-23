#include <bits/stdc++.h>
using namespace std;

/*
  Time complexity: O(n)
  Space complexity: O(n)
*/
int INT_MIN_VAL = -2147483648;
int INT_MAX_VAL = 2147483647;

int optimal(string s)
{
  int i, sign = 1;
  for (i = 0; i < s.size() && s[i] == ' '; i++)
    ;
  if (i < s.size() && (s[i] == '+' || s[i] == '-'))
  {
    sign = s[i] == '-' ? -1 : 1;
    i++;
  }
  return toNum(s, i, 0, sign);
}

int toNum(string st, int i, long long num, int sign)
{
  if (i >= st.size() || !isdigit(st[i]))
    return (int)sign * num;
  num = num * 10 + (st[i] - '0');
  if (sign * num <= INT_MIN_VAL)
    return INT_MIN_VAL;
  if (sign * num >= INT_MAX_VAL)
    return INT_MAX_VAL;
  return toNum(st, i + 1, num, sign);
}

/*------------------------------------*/

int main()
{
  string s;
  getline(cin, s);

  cout << optimal(s) << endl;
  return 0;
}