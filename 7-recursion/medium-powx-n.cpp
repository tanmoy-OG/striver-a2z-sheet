#include <bits/stdc++.h>
using namespace std;

/*
  Time complexity: O(n)
  Space complexity: O(1)
*/
double brute(double x, int n) {
        long long n1 = n;
        double ans = 1;
        if(x == 0)
            return 0;
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        if(n < 0)
            n1 *= -1;
        while(n1 > 0) {
            ans *= x;
            n1--;
        }
        if(n < 0)
            ans = 1 / ans;
        return ans;
    }

/*------------------------------------*/

/*
  Time complexity: O(logn)
  Space complexity: O(1)
*/
double optimalLoop(double x, int n) {
        long long n1 = n;
        double ans = 1;
        if(x == 0)
            return 0;
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        if(n < 0)
            n1 *= -1;
        while(n1 > 0) {
            if(n1%2) {
                ans *= x;
                n1--;
                continue;
            }
            x *= x;
            n1 /= 2;
        }
        if(n < 0)
            ans = 1 / ans;
        return ans;
    }

/*------------------------------------*/

/*
  Time complexity: O(logn)
  Space complexity: O(logn)
*/
double optimalRecursive(double x, int n)
{
  long long n1 = n;
  if (x == 0)
    return 0;
  if (n == 0)
    return 1;
  if (n == 1)
    return x;
  if (n < 0)
  {
    n1 *= -1;
    return 1 / (x * optimalRecursive(x, n1 - 1));
  }
  if (n % 2 == 0)
    return optimalRecursive(x * x, n1 / 2);
  return x * optimalRecursive(x, n1 - 1);
}

/*------------------------------------*/

int main()
{
  double x;
  int n;
  cin >> x;
  cin >> n;
  cout << brute(x, n) << endl;
  cout << optimalLoop(x, n) << endl;
  cout << optimalRecursive(x, n) << endl;
  return 0;
}