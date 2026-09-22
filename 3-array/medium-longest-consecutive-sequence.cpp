#include <bits/stdc++.h>

using namespace std;

/*
  Bruteforce approach: (Sorting)
  Time complexity: O(nlogn)
  Space complexity: O(1)
*/

int brute(vector<int> &nums)
{
  sort(nums.begin(), nums.end());
  int maxi = 0, last = INT_MIN, cnt = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == last + 1)
    {
      last = nums[i];
      cnt++;
      maxi = max(maxi, cnt);
    }
    else if (nums[i] > last + 1)
    {
      last = nums[i];
      cnt = 1;
      maxi = max(maxi, cnt);
    }
  }
  return maxi;
}

/*
  Optimized approach: (Hash Table)
  Time complexity: O(3n)
  Space complexity: O(n)
*/

int optimal(vector<int> &nums)
{
  int n = nums.size(), maxi = 1;
  if (n == 0)
    return 0;
  unordered_set<int> st;
  for (auto it : nums)
    st.insert(it);
  for (auto it : st)
    if (st.find(it - 1) == st.end())
    {
      int cnt = 1, x = it;
      while (st.find(x + 1) != st.end())
      {
        cnt++;
        x++;
      }
      maxi = max(maxi, cnt);
    }
  return maxi;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int k;
  cin >> k;

  cout << brute(arr) << endl;
  cout << optimal(arr) << endl;

  return 0;
}