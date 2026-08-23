#include <bits/stdc++.h>
using namespace std;

int MOD = 1000000007;

/*
  Time complexity: O(n)
  Space complexity: O(1)
*/
int brute(long long n)
{
  long long evenPos = (n + 1) / 2, oddPos = n / 2, evenTotal, oddTotal;
  evenTotal = brutePow(5, evenPos);
  oddTotal = brutePow(4, oddPos);
  return (int)evenTotal * oddTotal % MOD;
}

long long brutePow(long long x, long long n)
{
  long long ans = 1;
  if (n == 0)
    return 1;
  if (n == 1)
    return x;
  while (n > 0)
  {
    ans = ans * x % MOD;
    n--;
  }
  return ans;
}

/*------------------------------------*/

/*
  Time complexity: O(logn)
  Space complexity: O(1)
*/
int optimalLoop(long long n)
{
  long long evenPos = (n + 1) / 2, oddPos = n / 2, evenTotal, oddTotal;
  evenTotal = brutePow(5, evenPos);
  oddTotal = brutePow(4, oddPos);
  return (int)evenTotal * oddTotal % MOD;
}

long long optimalLoopPow(long long x, long long n)
{
  long long ans = 1;
  if (n == 0)
    return 1;
  if (n == 1)
    return x;
  while (n > 0)
  {
    if (n % 2)
    {
      ans = ans * x % MOD;
      n--;
      continue;
    }
    x = x * x % MOD;
    n /= 2;
  }
  return ans;
}

/*------------------------------------*/

/*
  Time complexity: O(logn)
  Space complexity: O(logn)
*/
int optimalRecursive(long long n)
{
  long long evenPos = (n + 1) / 2, oddPos = n / 2, evenTotal, oddTotal;
  evenTotal = optimalRecursivePow(5, evenPos);
  oddTotal = optimalRecursivePow(4, oddPos);
  return (int)evenTotal * oddTotal % MOD;
}

double optimalRecursivePow(double x, int n)
{
  if (n == 0)
    return 1;
  if (n == 1)
    return x;
  if (n % 2 == 0)
    return optimalRecursivePow(x * x, n / 2);
  return x * optimalRecursivePow(x, n - 1);
}

/*------------------------------------*/

int main()
{
  long long n;
  cin >> n;
  cout << brute(n) << endl;
  cout << optimalLoop(n) << endl;
  cout << optimalRecursive(n) << endl;
  return 0;
}