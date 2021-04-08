/**
 * Definition for singly-linked list.
 */
#include<iostream>
#include<vector>
#include<algorithm>
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int pi = 0;
        int* arr = new int [500 * 1e4 + 100];
        for(int i = 0 ; i < lists.size() ; i++)
        {
            ListNode* curr = lists[i] ;
            while(nullptr != curr)
            {
                arr[pi++] = curr->val;
                curr = curr->next;
            }
        }
        sort(arr, arr + pi );
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        for(int i = 0 ; i < pi ; i++)
        {
            curr->next = new ListNode( arr[i] );
            curr = curr -> next;
        }
        return head->next;
    }
};