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
ListNode *brute(ListNode *headA, ListNode *headB)
{
  unordered_map<ListNode *, int> mpp;
  ListNode *temp = headA;
  while (temp)
  {
    mpp[temp] = 1;
    temp = temp->next;
  }
  temp = headB;
  while (temp)
  {
    if (mpp.find(temp) != mpp.end())
      return temp;
    temp = temp->next;
  }
  return NULL;
}

/*------------------------------------*/

/*
  Time complexity: O(3n)
  Space complexity: O(n)
*/
ListNode *better(ListNode *headA, ListNode *headB)
{
  ListNode *temp1 = headA, *temp2 = headB;
  int cnt1 = 0, cnt2 = 0;
  while (temp1)
  {
    cnt1++;
    temp1 = temp1->next;
  }
  while (temp2)
  {
    cnt2++;
    temp2 = temp2->next;
  }
  temp1 = headA;
  temp2 = headB;
  while (cnt1 > cnt2)
  {
    cnt1--;
    temp1 = temp1->next;
  }
  while (cnt1 < cnt2)
  {
    cnt2--;
    temp2 = temp2->next;
  }
  while (temp1 != temp2)
  {
    temp1 = temp1->next;
    temp2 = temp2->next;
  }
  return temp1;
}

/*------------------------------------*/

/*
  Time complexity: O(2n)
  Space complexity: O(1)
*/
ListNode *optimal(ListNode *headA, ListNode *headB)
{
  ListNode *temp1 = headA, *temp2 = headB;
  while (temp1 != temp2)
  {
    temp1 = temp1->next;
    temp2 = temp2->next;
    if (temp1 == temp2)
      return temp1;
    if (temp1 == NULL)
      temp1 = headB;
    if (temp2 == NULL)
      temp2 = headA;
  }
  return temp1;
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

  cout << brute(headA, headB)->val << endl;
  cout << better(headA, headB)->val << endl;
  cout << optimal(headA, headB)->val << endl;
  return 0;
}