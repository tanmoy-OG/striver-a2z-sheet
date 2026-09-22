#include <bits/stdc++.h>

using namespace std;

/*
  Optimized approach:
  Time complexity: O(n * wordLength * 26 * (n or 1)) (no of items in arrar or the times loop for queue executes * for each iteration, word change happens for 26 times for each character in the word * search through set for each such word generation)
  Space complexity: O(2n) (visited matrix + recursion stack space)
*/

int optimal(string beginWord, string endWord, vector<string> &wordList)
{
  unordered_set<string> st(wordList.begin(), wordList.end());
  if (st.find(endWord) == st.end())
    return 0;
  queue<pair<string, int>> q;
  st.erase(beginWord);
  q.push({beginWord, 1});
  while (!q.empty())
  {
    string word = q.front().first;
    int lvl = q.front().second;
    q.pop();
    if (word == endWord)
      return lvl;
    for (int i = 0; i < word.size(); i++)
      nextWord(i, word, st, q, lvl);
  }
  return 0;
}
void nextWord(int i, string word, unordered_set<string> &st, queue<pair<string, int>> &q, int lvl)
{
  for (char ch = 'a'; ch <= 'z'; ch++)
  {
    word[i] = ch;
    if (st.find(word) != st.end())
    {
      q.push({word, lvl + 1});
      st.erase(word);
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

  cout << optimal(startWord, endWord, arr) << endl;

  return 0;
}