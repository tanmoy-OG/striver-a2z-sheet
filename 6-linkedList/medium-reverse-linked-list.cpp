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
  if (head == NULL)
    return head;
  stack<int> st;
  ListNode *temp = head;
  while (temp)
  {
    st.push(temp->val);
    temp = temp->next;
  }
  ListNode *ans = new ListNode(st.top());
  temp = ans;
  st.pop();
  while (st.size())
  {
    temp->next = new ListNode(st.top());
    temp = temp->next;
    st.pop();
  }
  return ans;
}

/*------------------------------------*/

/*
  Time complexity: O(n)
  Space complexity: O(1)
*/
ListNode *optimal(ListNode *head)
{
  ListNode *temp = head;
  ListNode *prev = NULL;
  while (temp)
  {
    ListNode *next = temp->next;
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

  cout << brute(head)->val << endl;
  cout << optimal(head)->val << endl;
  return 0;
}