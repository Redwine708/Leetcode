struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if(head == nullptr || head -> next == nullptr)return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast -> next)
        {
            fast  = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow)
            {
                break;
            }
        }
        if(fast != slow)return nullptr;
        fast = head;
        while(fast != slow)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
        return fast;
        
    }
};