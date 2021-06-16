// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        //two empty tree
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr && q != nullptr) return false;
        if(p != nullptr && q == nullptr) return false;
        //if the value of two nodes is not equal
        if(p->val != q->val) return false;
        else
        {
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }
    }
};