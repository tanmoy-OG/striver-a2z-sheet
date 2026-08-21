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
  Time complexity: O(n^2)
  Space complexity: O(1)
*/
ListNode *brute(ListNode *head)
{
  if (head == NULL)
    return head;
  ListNode *first = head, *second = NULL;
  while (first->next != NULL)
  {
    second = first->next;
    while (second)
    {
      if (second->val < first->val)
      {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
      }
      second = second->next;
    }
    first = first->next;
  }
  return head;
}

/*------------------------------------*/

/*
  Time complexity: O(2n+nlogn)
  Space complexity: O(n)
*/
ListNode *better(ListNode *head)
{
  if (head == NULL)
    return head;
  ListNode *temp = head;
  map<int, int> mp;
  while (temp)
  {
    mp[temp->val]++;
    temp = temp->next;
  }
  temp = head;
  for (auto it : mp)
  {
    for (int i = 1; i <= it.second; i++)
    {
      temp->val = it.first;
      temp = temp->next;
    }
  }
  return head;
}

/*------------------------------------*/

/*
  Time complexity: O(nlogn)
  Space complexity: O(1)
*/
ListNode *optimal(ListNode *head)
{
  if (head == NULL || head->next == NULL)
    return head;
  ListNode *temp = head, *mid, *leftHead, *rightHead;
  mid = middle(head);
  leftHead = head;
  rightHead = mid->next;
  mid->next = NULL;
  leftHead = optimal(leftHead);
  rightHead = optimal(rightHead);
  head = merge(leftHead, rightHead);
  return head;
}

ListNode *middle(ListNode *head)
{
  ListNode *tortoise = head, *hare = head;
  while (hare->next != NULL && hare->next->next != NULL)
  {
    tortoise = tortoise->next;
    hare = hare->next->next;
  }
  return tortoise;
}

ListNode *merge(ListNode *leftHead, ListNode *rightHead)
{
  ListNode *dummy = new ListNode(-1), *temp = dummy;
  while (leftHead && rightHead)
  {
    if (leftHead->val <= rightHead->val)
    {
      temp->next = leftHead;
      leftHead = leftHead->next;
    }
    else
    {
      temp->next = rightHead;
      rightHead = rightHead->next;
    }
    temp = temp->next;
  }
  while (leftHead)
  {
    temp->next = leftHead;
    leftHead = leftHead->next;
    temp = temp->next;
  }
  while (rightHead)
  {
    temp->next = rightHead;
    rightHead = rightHead->next;
    temp = temp->next;
  }
  return dummy->next;
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
  cout << better(head)->val << endl;
  cout << optimal(head)->val << endl;
  return 0;
}