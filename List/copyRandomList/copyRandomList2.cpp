/*
 *URL :  https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/
 *Second solution
 *Use only one list. 
 *And Splice the list
 */

// Definition for a Node.
#include<unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)return nullptr;
        Node* curr = head;
        while(curr)
        {
            Node* tmp = new Node(curr->val);
            tmp->next = curr->next;
            curr->next = tmp;
            curr = tmp->next;
        }
        curr = head;
        while(curr)
        {
            if(curr->random != nullptr){
            curr -> next -> random = curr -> random -> next;
            }
            curr = curr -> next -> next;
        }
        Node* pre = head;
        Node* res = head->next;
        curr = head -> next;
        while(curr -> next)
        {
            pre->next = pre -> next -> next;
            curr -> next = curr -> next -> next;
            pre = pre->next;
            curr = curr->next;
        }
        pre->next = nullptr;
        return res;

    }
};