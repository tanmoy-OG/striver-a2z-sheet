#include <bits/stdc++.h>

using namespace std;

/*
  Optimized approach:
  Time complexity: O(n * wordLength * 26 * (n or 1)) (no of items in array or the times loop for queue executes * for each iteration, word change happens for 26 times for each character in the word * search through set for each such word generation)
  Space complexity: O(2n) (visited matrix + recursion stack space)
*/

vector<vector<string>> optimal(string beginWord, string endWord, vector<string> &wordList)
{
  queue<vector<string>> q;
  unordered_set<string> st(wordList.begin(), wordList.end());
  vector<vector<string>> ans;
  vector<string> vis;
  int lvl = 0;
  q.push({beginWord});
  vis.push_back(beginWord);
  while (!q.empty())
  {
    vector<string> v = q.front();
    q.pop();
    if (v.size() > lvl)
    {
      lvl++;
      for (auto it : vis)
        st.erase(it);
    }
    vis.clear();
    string word = v.back();
    if (word == endWord)
    {
      if (ans.size() == 0)
        ans.push_back(v);
      else if (ans[0].size() == v.size())
        ans.push_back(v);
    }
    for (int i = 0; i < word.size(); i++)
      nextWord(i, word, v, vis, st, q);
  }
  return ans;
}
void nextWord(int i, string word, vector<string> &v, vector<string> &vis, unordered_set<string> &st, queue<vector<string>> &q)
{
  for (char ch = 'a'; ch <= 'z'; ch++)
  {
    word[i] = ch;
    if (st.find(word) != st.end())
    {
      v.push_back(word);
      vis.push_back(word);
      q.push(v);
      v.pop_back();
    }
  }
}

/*------------------------------------*/

int main()
{
  int n;
  cin >> n;
  vector<string> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  string startWord, endWord;
  cin >> startWord;
  cin >> endWord;

  vector<vector<string>> ans = optimal(startWord, endWord, arr);
  for (auto it : ans)
  {
    for (auto jt : it)
      cout << jt << " ";
    cout << endl;
  }

  return 0;
}