
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
    ListNode *partition(ListNode *head, int x)
    {
        //smaller than x
        ListNode* small = new ListNode(0);
        ListNode* smallhead = small;
        //not smaller than x
        ListNode* noSmall = new ListNode(0);
        ListNode* noSmallHead = noSmall;
        while(head)
        {
            if(head->val < x)
            {
                small->next = head;
                small = small->next;
            }
            else{
                noSmall->next = head;
                noSmall = noSmall -> next;
            }
            head = head -> next;
        }
        noSmall->next = nullptr;
        small->next = noSmallHead -> next;
        ListNode* temp = smallhead->next;
        //release space
        delete smallhead;
        delete noSmallHead;
        return temp;
    }
};