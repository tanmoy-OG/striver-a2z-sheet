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
  ListNode *temp = head;
  int cnt = 0;
  while (temp)
  {
    cnt++;
    temp = temp->next;
  }
  if (cnt == 1) {
    delete head;
    return nullptr;
  }
  temp = head;
  cnt /= 2;
  while (temp)
  {
    cnt--;
    if (cnt == 0)
    {
      ListNode *del = temp->next;
      temp->next = temp->next->next;
      delete del;
      break;
    }
    temp = temp->next;
  }
  return head;
}

/*------------------------------------*/

/*
  Time complexity: O(n/2)
  Space complexity: O(1)
*/
ListNode *optimal(ListNode *head, int n)
{
  ListNode *tortoise = head, *hare = head, *del = NULL;
  if (hare->next == NULL) {
    delete head;
    return nullptr;
  }
  while (hare->next->next != NULL && hare->next->next->next != NULL)
  {
    tortoise = tortoise->next;
    hare = hare->next->next;
  }
  del = tortoise->next;
  tortoise->next = tortoise->next->next;
  delete del;
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