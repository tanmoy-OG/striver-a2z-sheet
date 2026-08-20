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
bool brute(ListNode *head)
{
  ListNode *temp = head;
  stack<int> st;
  while (temp)
  {
    st.push(temp->val);
    temp = temp->next;
  }
  temp = head;
  while (temp)
  {
    if (temp->val != st.top())
      return false;
    st.pop();
    temp = temp->next;
  }
  return true;
}

/*------------------------------------*/

/*
  Time complexity: O(2n)
  Space complexity: O(1)
*/
bool optimal(ListNode *head)
{
  ListNode *first = head, *second = NULL, *tortoise = head, *hare = head, *newHead = NULL;
  bool isPalin = true;
  while (hare->next != NULL && hare->next->next != NULL)
  {
    tortoise = tortoise->next;
    hare = hare->next->next;
  }
  newHead = reverse(tortoise->next);
  second = newHead;
  while (second)
  {
    if (first->val != second->val)
    {
      isPalin = false;
      break;
    }
    first = first->next;
    second = second->next;
  }
  newHead = reverse(newHead);
  return isPalin;
}

ListNode *reverse(ListNode *head)
{
  ListNode *temp = head, *prev = NULL, *next = NULL;
  while (temp)
  {
    next = temp->next;
    temp->next = prev;
    prev = temp;
    temp = next;
  }
  return prev;
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