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
  ListNode *temp = head, *prev = NULL, *next = NULL, *kNode = NULL;
  while (temp)
  {
    kNode = findK(temp, k);
    if (kNode == NULL)
    {
      if (prev)
        prev->next = temp;
      break;
    }
    next = kNode->next;
    kNode->next = NULL;
    listReverse(temp);
    if (temp == head)
      head = kNode;
    else
      prev->next = kNode;
    prev = temp;
    temp = next;
  }
  return head;
}

ListNode *findK(ListNode *head, int k)
{
  ListNode *temp = head;
  int cnt = 1;
  while (temp && cnt < k)
  {
    cnt++;
    temp = temp->next;
  }
  return temp;
}

void listReverse(ListNode *head)
{
  ListNode *temp = head, *prev = NULL;
  while (temp)
  {
    ListNode *next = temp->next;
    temp->next = prev;
    prev = temp;
    temp = next;
  }
  return;
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