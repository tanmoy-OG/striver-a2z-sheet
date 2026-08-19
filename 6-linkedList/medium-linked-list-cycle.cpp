#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
  Time complexity: O(n + (2log n or 2x1))
  Space complexity: O(n)
*/
bool brute(ListNode *head)
{
  unordered_map<ListNode *, int> mpp;
  ListNode *temp = head;
  while (temp)
  {
    if (mpp.find(temp) != mpp.end())
      return true;
    mpp[temp] = 1;
    temp = temp->next;
  }
  return false;
}

/*------------------------------------*/

/*
  Time complexity: O(n)
  Space complexity: O(1)
*/
bool optimal(ListNode *head)
{
  ListNode *tortoise = head;
  ListNode *hare = head;
  while (hare && hare->next != NULL)
  {
    tortoise = tortoise->next;
    hare = hare->next->next;
    if (tortoise == hare)
      return true;
  }
  return false;
}

/*------------------------------------*/

int main()
{
  int n;
  cin >> n;
  ListNode *head = new ListNode(n);
  ListNode *temp = head;
  while (cin >> n)
  {
    temp->next = new ListNode(n);
    temp = temp->next;
  }

  cout << brute(head) << endl;
  cout << optimal(head) << endl;
  return 0;
}