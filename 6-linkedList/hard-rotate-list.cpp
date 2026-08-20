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
ListNode *optimal(ListNode *head, int k)
{
  if (head == NULL || head->next == NULL)
    return head;
  ListNode *temp = head;
  int cnt = 1;
  while (temp->next != NULL)
  {
    cnt++;
    temp = temp->next;
  }
  temp->next = head;
  k %= cnt;
  cnt -= k;
  temp = head;
  while (cnt > 1)
  {
    cnt--;
    temp = temp->next;
  }
  head = temp->next;
  temp->next = NULL;
  return head;
}

/*------------------------------------*/

int main()
{
  int n, k;
  cin >> n;
  ListNode *head = new ListNode(n);
  ListNode *temp = head;
  while (cin >> n)
  {
    temp->next = new ListNode(n);
    temp = temp->next;
  }
  cin >> k;

  cout << optimal(head, k)->val << endl;
  return 0;
}