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
    void Swap(int &a , int &b)
    {
        int temp = a;
        a = b; 
        b = temp;
    }
    void Segment(int arr[] , int start , int end )
    {
        int i = start ; 
        int j = end - 1;
       while( i <= j )
       {
           Swap(arr[i++] , arr[j--]);
       }
    }

    ListNode* reverseKGroup(ListNode *head, int k)
    {
        int* arr = new int [ 5000 + 100 ];
        for( int i = 0 ; i < 5000 + 100 ; i++ )
        {        
            arr[i] = 0;
        }
        int pi = 0;
        ListNode* curr = head;
        while(curr)
        {
            arr[pi++] = curr->val;
            curr = curr -> next;
        }
        for(int i = 0 ; i + k < pi ; i += k)
        {
            Segment(arr, i , i + k);
        }
        int q = 0;
        curr = head;
        while(curr)
        {
            curr -> val = arr[q++];
            curr = curr->next;
        }
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
    curr = head;
     while( curr != NULL)
    {
        cout<<curr->val<<" ";
        curr = curr->next;
    }
    cout<<endl;
    Solution s;
    head = s.reverseKGroup(head,2);
    curr = head;
    while( curr != NULL)
    {
        cout<<curr->val<<" ";
        curr = curr->next;
    }
}