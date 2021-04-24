/*
 *URL :  https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/
 *First solution 
 *Use map to construct key and value:key stands for the old node, value stands for the new node.
 *This will traverse the node twice.
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
        unordered_map<Node*, Node*> map;
        while(curr)
        {
            map[curr] = new Node (curr->val);
            curr = curr -> next;
        }
        curr = head;
        while(curr)
        {
            map[curr] -> next   = map[ curr-> next ];
            map[curr] -> random = map[ curr -> random ] ;
            curr = curr -> next;
        }
        return map[head];

    }
};