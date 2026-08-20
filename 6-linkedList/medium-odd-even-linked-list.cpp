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
  Time complexity: O(2n)
  Space complexity: O(n)
*/
ListNode *brute(ListNode *head)
{
  vector<int> odd, even;
  ListNode *temp = head;
  int cnt = 1;
  while (temp)
  {
    if (cnt % 2 == 0)
      even.push_back(temp->val);
    else
      odd.push_back(temp->val);
    cnt++;
    temp = temp->next;
  }
  temp = head;
  for (auto it : odd)
  {
    temp->val = it;
    temp = temp->next;
  }
  for (auto it : even)
  {
    temp->val = it;
    temp = temp->next;
  }
  return head;
}

/*------------------------------------*/

/*
  Time complexity: O(n)
  Space complexity: O(1)
*/
ListNode *optimal(ListNode *head)
{
  if (head == NULL || head->next == NULL)
    return head;
  ListNode *odd = head, *even = head->next, *evenStart = even;
  while (even != NULL && even->next != NULL)
  {
    odd->next = odd->next->next;
    even->next = even->next->next;
    odd = odd->next;
    even = even->next;
  }
  odd->next = evenStart;
  return head;
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

  cout << brute(head)->val << endl;
  cout << optimal(head)->val << endl;
  return 0;
}