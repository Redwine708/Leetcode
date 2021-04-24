/*
 *Use unordered_set and push ListNode in it.
 *if the ListNode already exists,return head.
 *else insert it in the set.
 */
#include<iostream>
#include<unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
       unordered_set<ListNode*>hash;
       while(head != NULL)
       {
           if(hash.count(head))
           {
               return head;
           }
           else{
               hash.insert(head);
               head = head -> next;
           }
       }
       return NULL;
    }
};

int main()
{

}