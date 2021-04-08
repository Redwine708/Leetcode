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
//Recursive
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
       ListNode* dummy = new ListNode(0,head);
       ListNode* prev = dummy;
       while( prev -> next != nullptr&&prev ->next->next != nullptr  )
       {
           ListNode* node1 = prev -> next;
           ListNode* node2 = prev -> next -> next;
           node1 -> next = node2 -> next;
           node2 -> next = node1 ;
           prev -> next = node2;
           prev = node1;
       }
       return dummy -> next;
    }
};

int main()
{
    ListNode* head = new ListNode(0);
    ListNode* curr = head;
    cout<<head->val<<" ";
    for(int i = 1 ; i< 5 ; i++)
    {
        curr->next = new ListNode(i);
        cout<<curr->next->val<<" ";
        curr = curr -> next;
        
    }
    cout<<endl;
    Solution s;
    curr = s.swapPairs(head);
   
    while(curr != NULL)
    {
        cout<<curr->val<<" ";
        curr = curr -> next;
    } 
}