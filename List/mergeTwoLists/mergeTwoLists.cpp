/**
 * Definition for singly-linked list.
 */
#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
      ListNode* preHead = new ListNode(-1);
      ListNode* prev = preHead;
      while(l1 != nullptr && l2 != nullptr)
      {
          if(l1 -> val < l2 -> val)
          {
              prev -> next = l1;
              l1 = l1 -> next;
          }
          else 
          {
              prev -> next = l2;
              l2 = l2 -> next;
          }
          prev = prev -> next;
      }
      prev -> next = l1 ==nullptr ? l2 : l1;
      ListNode* temp = preHead;
      preHead = preHead -> next;
      delete temp;
      return preHead;
    }
};

int main()
{
    ListNode*l1 = new ListNode(0);
    ListNode*l2 = new ListNode(5);
    ListNode* curr = l1;
    for(int i = 1 ; i < 5 ; i++)
    {
        curr -> next = new ListNode(i);
        curr = curr->next;
    }
    curr = l2;
    for(int i = 5 ; i < 10 ;i++ )
    {
        curr -> next = new ListNode(i);
        curr = curr -> next;
    }
    Solution s;
    curr = s.mergeTwoLists(l1 , l2);
    while(curr)
    {
        cout<<curr -> val<<" ";
        curr= curr->next;
    }

}