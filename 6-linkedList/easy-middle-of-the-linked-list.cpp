#include <bits/stdc++.h>
using namespace std;

class ListNode {
    public:
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

/*
  Time complexity: O(n+n/2)
  Space complexity: O(1)
*/
ListNode* brute(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp) {
            cnt++;
            temp = temp->next;
        }
        int mid = cnt/2+1;
        cnt = 0;
        temp = head;
        while(cnt <= mid) {
            cnt++;
            if(cnt == mid)
                return temp;
            temp = temp->next;
        }
        return temp;
    }

/*------------------------------------*/

/*
  Time complexity: O(n)
  Space complexity: O(1)
*/
ListNode* optimal(ListNode* head) {
        ListNode* tortoise = head;
        ListNode* hare = head;
        while (hare && hare->next) {
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        return tortoise;
    }

/*------------------------------------*/

int main() {
  int n;
  cin >> n;
  ListNode* head = new ListNode(n);
  ListNode* temp = head;
  while(cin >> n) {
    temp->next = new ListNode(n);
    temp = temp->next;
  }

  cout << brute(head)->val << endl;
  cout << optimal(head)->val << endl;
  return 0;
}