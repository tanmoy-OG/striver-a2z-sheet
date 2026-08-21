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
  Time complexity: O(n)
  Space complexity: O(1)
*/
ListNode *optimal(ListNode *l1, ListNode *l2)
{
  ListNode *dummy = new ListNode(), *temp = dummy, *temp1 = l1, *temp2 = l2;
  int sum, carry = 0;
  while (temp1 || temp2 || carry)
  {
    sum = carry;
    if (temp1)
    {
      sum += temp1->val;
      temp1 = temp1->next;
    }
    if (temp2)
    {
      sum += temp2->val;
      temp2 = temp2->next;
    }
    carry = sum / 10;
    sum %= 10;
    ListNode *node = new ListNode(sum);
    temp->next = node;
    temp = temp->next;
  }
  return dummy->next;
}

/*------------------------------------*/

int main()
{
  int n;
  cin >> n;
  ListNode *headA = new ListNode(n);
  ListNode *temp = headA;
  while (cin >> n)
  {
    temp->next = new ListNode(n);
    temp = temp->next;
  }

  cin >> n;
  ListNode *headB = new ListNode(n);
  temp = headB;
  while (cin >> n)
  {
    temp->next = new ListNode(n);
    temp = temp->next;
  }

  cout << optimal(headA, headB)->val << endl;
  return 0;
}