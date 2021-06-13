/*
 *Problem 328
 */
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
    ListNode *oddEvenList(ListNode *head)
    {
        if(head == nullptr)return nullptr;  //空链表特判
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;
        while(even!=nullptr && even->next!=nullptr)
        {
            odd -> next = even -> next;
            odd = even -> next;
            even -> next = odd -> next;
            even = odd -> next;
        }
        odd -> next = evenHead;
        return head;
    }
};