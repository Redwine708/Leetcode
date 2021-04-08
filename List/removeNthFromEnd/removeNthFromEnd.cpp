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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode* dummy = new ListNode(0,head);
        ListNode* first = head;
        ListNode* second = dummy;
        //距离n个位置
        for(int i = 0 ; i < n ; i++ )
        {
            first = first -> next;
        }
        //进行向下找，直到首节点到达末=空
        while(first != nullptr)
        {
            first = first -> next;
            second = second -> next;
        }
        ListNode* temp = second -> next;
        second -> next = second -> next -> next;
        delete temp;
        head = dummy -> next;
        delete dummy;
        return head;
    }
};

int main()
{
    ListNode* head = new ListNode(0);
    ListNode* curr = head;
    for(int i = 1 ; i< 5; i++)
    {
        curr -> next = new ListNode(i);
        curr = curr -> next;
    }
    Solution s;
    head = s.removeNthFromEnd(head, 2);
    curr = head;
    while( curr != NULL)
    {
        cout<<curr->val;
        curr = curr->next;
    }

}