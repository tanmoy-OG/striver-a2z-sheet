#include <bits/stdc++.h>

using namespace std;

/*
  Brute force approach:
  Time complexity: O(n)
  Space complexity: O(n)

  Algo: To find all possible permutations of the array and store it in an array or arrays, using next_permutation STL library. Then iterating through it to find the original permutation, and returning the next one.
*/

/*
  Optimal approach:
  Time complexity: O(n)
  Space complexity: O(1)
*/

void nextPermuteOpti(vector<int> &nums) {
  int i, j;
    for(i = nums.size()-2; i>=0; i--)
      if(nums[i] < nums[i+1])
        break;
    if(i==-1) {
      reverse(nums.begin(), nums.end());
        return;
    }
    for(j = nums.size()-1; j > i; j--)
      if(nums[j] > nums[i]) {
        swap(nums[j], nums[i]);
          break;
        }
    reverse(nums.begin()+i+1, nums.end());
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  nextPermuteOpti(arr);

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  return 0;
}