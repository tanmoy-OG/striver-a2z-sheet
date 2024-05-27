#include <bits/stdc++.h>

using namespace std;

int largest(vector<int> &arr, int n) {
  int mini = INT_MIN;
  for (auto i : arr)
    if (i > mini)
      mini = i;
  return mini;
}