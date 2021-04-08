
//Definition for singly-linked list.
#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *removeDuplicateNodes(ListNode *head)
    {
        if(head == NULL) return head;
        int* hash = new int[20001];
        for(int i = 0 ; i< 20001 ; i++)
        {
            hash[i] = false;
        }
        ListNode* curr = head;
        hash[curr->val] = true;
        while( curr->next != NULL)
        {
            if(hash[curr->next-> val])
            {
                curr->next = curr->next->next;
                continue;
            }
            hash[curr-> val] = true;
            curr = curr ->next;
        }
        return head;
    }
};
int main()
{
    ListNode* head = new ListNode(4);
    ListNode* curr = head;
    for(int i = 0 ; i < 5 ; i ++)
    {
        curr->next = new ListNode(i);
        curr = curr -> next; 
    }
    curr = head;
    Solution s;
    while(curr != NULL) 
    {
        cout<<curr->val<<" ";
        curr = curr -> next;
    }
    cout<<endl;
    curr = s.removeDuplicateNodes(head);
    while(curr != NULL) 
    {
        cout<<curr->val<<" ";
        curr = curr -> next;
    }
}
