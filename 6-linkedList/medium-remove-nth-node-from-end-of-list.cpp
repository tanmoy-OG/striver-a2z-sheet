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
  Space complexity: O(1)
*/
ListNode *brute(ListNode *head, int n)
{
  ListNode *temp = head, *prev = NULL;
  int cnt = 0, pos;
  while (temp)
  {
    cnt++;
    temp = temp->next;
  }
  pos = cnt - n + 1;
  cnt = 0;
  temp = head;
  while (temp)
  {
    cnt++;
    if (cnt == pos)
    {
      if (temp == head)
        head = temp->next;
      else
        prev->next = temp->next;
      delete temp;
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
}

/*------------------------------------*/

/*
  Time complexity: O(n)
  Space complexity: O(1)
*/
ListNode *optimal(ListNode *head, int n)
{
  ListNode *temp = head, *prev = head, *dlt = NULL;
  for (int i = 0; i < n; i++)
    temp = temp->next;
  if (temp == NULL)
  {
    dlt = head;
    head = head->next;
    delete dlt;
    return head;
  }
  while (temp->next != NULL)
  {
    temp = temp->next;
    prev = prev->next;
  }
  dlt = prev->next;
  prev->next = prev->next->next;
  delete dlt;
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
  cin >> n;

  cout << brute(head, n)->val << endl;
  cout << optimal(head, n)->val << endl;
  return 0;
}